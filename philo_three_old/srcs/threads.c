/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 14:58:32 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/28 11:36:19 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int		get_time(void)
{
	struct timeval	tv;
	int				i;

	gettimeofday(&tv, NULL);
	i = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (i);
}

void	check_philo(t_data *t)
{
	int			i;
	int			j;

	i = 0;
	while (i < t->nb_of_meals)
	{
		j = 0;
		while (j < t->nb_of_philo)
		{
			sem_wait(t->phil[j].gen_lock);
			j++;
		}
		i++;
	}
	aff(t->phil, 6);
}

void	*is_he_dead(void *args)
{
	t_philo		*p;

	p = args;
	while (p->ping && g_point != -1)
	{
		sem_wait(p->lock_eat);
		if (chronos() - p->time > p->t->time_die)
		{
			p->ping = 0;
			sem_post(p->lock_eat);
			aff(p, 5);
		}
		sem_post(p->lock_eat);
		usleep(100);
	}
	return (NULL);
}

int		start_routine(t_data *t, int i)
{
	pthread_t	*thread;
	t_philo		*p;

	p = malloc(sizeof(t_philo));
	if (!p)
		exit(2);
		thread = malloc(sizeof(pthread_t));
	if (!thread)
	{
		free(p);
		exit(2);
	}
	// 
	if (pthread_create(&thread, NULL, &is_he_dead, (void*)p))
		return (1);
	pthread_detach(thread);
	while (p->done != -1)
	{
		ft_frk(p);
		eat(p);
		ft_frk_no(p);
		sleeping(p);
		aff(p, 4);
	}
	sem_post(p->t->lock_forks);
	sem_post(p->t->lock_forks);
	sem_post(p->lock_eat);
	sem_post(p->gen_lock);
	return (0);
}

int		init_process(t_data *t, int i)
{
	int	pid[t->nb_of_philo + 1];

	t->time = get_time();
	while (i < t->nb_of_philo)
	{
		if (!(pid[i] = fork()))
			start_routine(t, i);
		else if (pid[i] < 0)
			return (1);
		usleep(100); //
		i++;
	}
	//
	if (t->nb_of_meals > 0)
	{
		if (!(t->pid = fork()))
			check_philo(t);
	}
	waitpid(-1, NULL, 0);
	return (0);
}
