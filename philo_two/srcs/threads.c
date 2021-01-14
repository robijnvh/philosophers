/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 14:58:32 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/14 11:12:59 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

int		check_philo(void *args)
{
	t_philo			*p;

	p = args;
	if (p->meals_eaten >= p->t->nb_of_meals)
		p->t->cnt++;
	if (p->t->cnt == p->t->nb_of_philo)
	{
		print(p, 6);
		return (1);
	}
	return (0);
}

void	*is_he_dead(void *arg)
{
	t_philo		*p;

	p = arg;
	while (!p->t->done)
	{
		sem_wait(p->lock_eat);
		if (!p->t->done && get_time() - p->time > p->t->time_die)
		{
			print(p, 5);
			sem_post(p->lock_eat);
			return (NULL);
		}
		sem_post(p->lock_eat);
		usleep(100);
	}
	return (NULL);
}

void	*start_routine(void *inst)
{
	t_philo		*p;

	p = inst;
	p->time = get_time();
	while (!p->t->done)
	{
		ft_fork(p);
		if (p->t->done)
			break ;
		ft_eat(p);
		if (p->t->done)
			break ;
		ft_drop_fork(p);
		if (p->t->nb_of_meals > 0 && check_philo(p))
			break ;
		if (p->t->done)
			break ;
		ft_sleep(p);
		print(p, 4);
	}
	sem_post(p->t->lock_forks);
	sem_post(p->t->lock_forks);
	sem_post(p->t->lock_text);
	return (NULL);
}

int		init_threads(t_data *t)
{
	int			i;
	pthread_t	thread;

	i = 0;
	t->time = get_time();
	while (i < t->nb_of_philo)
	{
		t->phil[i].time = get_time();
		if (pthread_create(&thread, NULL, start_routine,
			(void*)&t->phil[i]))
			return (1);
		pthread_detach(thread);
		if (pthread_create(&t->phil[i].thread, NULL,
			&is_he_dead, (void*)&t->phil[i]))
			return (1);
		usleep(1000);
		i++;
	}
	i = 0;
	while (i < t->nb_of_philo)
	{
		pthread_join(t->phil[i].thread, NULL);
		i++;
	}
	return (0);
}
