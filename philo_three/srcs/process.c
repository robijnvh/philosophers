/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 11:56:41 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/28 10:28:44 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	*check_none_dead(void *void_t)
{
	t_data	*t;
	int		i;

	i = 0;
	t = (t_data*)void_t;
	sem_wait(t->lock_gen);
	while (i < t->nb_of_philo)
	{
		kill(t->pid[i], SIGTERM);
		i++;
	}
	return (NULL);
}

void	*check_if_dead(void *void_p)
{
	t_philo *p;

	p = (t_philo*)void_p;
	while (p->done == false)
	{
		if (is_food_ready(p, 2))
		{
			p->last = 1;
			print(get_time(), 5, p);
			sem_post(p->p_lock_gen);
			return (NULL);
		}
	}
	return (NULL);
}

void	continue_routine(pthread_t *thread, t_philo *p, t_data *t)
{
	while (p->meals != 0)
	{
		if (ft_eat(p, t) == 2)
			exit_routine_2(thread, p);
		if (ft_sleep(p) == 2)
			exit_routine_2(thread, p);
		if (print(get_time(), 4, p))
			exit_routine_2(thread, p);
		if (p->meals > 0)
			p->meals--;
	}
	p->done = true;
	pthread_join(thread[0], NULL);
	if (print(get_time(), 0, p))
		exit_routine_2(thread, p);
	free(thread);
	free(p);
	exit(2);
}

void	start_routine(t_data *t, int i)
{
	t_philo		*p;
	pthread_t	*thread;

	p = malloc(sizeof(t_philo));
	if (!p)
		exit(2);
	thread = malloc(sizeof(pthread_t));
	if (!thread)
	{
		free(p);
		exit(2);
	}
	set_data(t, p, i);
	p->p_lock_text = sem_open(SEM_TEXT, 0);
	p->p_lock_eat = sem_open(SEM_EAT, 0);
	p->p_lock_gen = sem_open(SEM_GEN, 0);
	if (p->p_lock_gen == SEM_FAILED || p->p_lock_eat == SEM_FAILED
	|| p->p_lock_text == SEM_FAILED)
		exit_routine(thread, p);
	if (pthread_create(&thread[0], NULL, check_if_dead, p))
		exit_routine(thread, p);
	continue_routine(thread, p, t);
}

int		start_process(t_data *t, int i)
{
	int	pid[t->nb_of_philo + 1];

	t->time = get_time();
	while (i < t->nb_of_philo)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			start_routine(t, i);
		ft_snooze_nano(4000);
		i++;
	}
	t->pid = pid;
	ft_snooze_nano(1000);
	if (pthread_create(&t->thread[0], NULL, check_none_dead, t))
		return (write_error("Error: thread creation failed\n"));
	while (i > 0)
	{
		i--;
		if (waitpid(pid[i], NULL, 0) == -1)
			return (write_error("Error: waitpid failed\n"));
	}
	if (sem_post(t->lock_gen) == -1)
		return (write_error("Error: sem_post failed\n"));
	if (pthread_join(t->thread[0], NULL))
		return (write_error("Error: thread join failed\n"));
	return (0);
}
