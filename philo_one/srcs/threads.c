/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 14:58:32 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/21 14:36:04 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

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

void	*check_if_dead(void *arg)
{
	t_philo		*p;

	p = arg;
	while (!p->t->done)
	{
		if (pthread_mutex_lock(&p->eat) == -1)
		{
			p->t->done = 1;
			return (NULL);
		}
		if (!p->t->done && get_time() - p->time > p->t->time_die)
		{
			print(p, 5);
			pthread_mutex_unlock(&p->eat);
			return (NULL);
		}
		if (pthread_mutex_unlock(&p->eat) == -1)
		{
			p->t->done = 0;
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

void	*start_routine(void *arg)
{
	t_philo		*p;

	p = arg;
	p->time = get_time();
	while (!p->t->done)
	{
		if (ft_eat(p))
		{
			write(2, "Error: mutex_lock failed\n", 25);
			break ;
		}
		if (p->t->nb_of_meals > 0 && check_philo(p))
			break ;
		if (p->t->done)
			break ;
		if (ft_sleep(p))
			break ;
		if (print(p, 4))
			break ;
	}
	pthread_mutex_unlock(&p->t->fork[p->fork_l]);
	pthread_mutex_unlock(&p->t->fork[p->fork_r]);
	pthread_mutex_unlock(&p->t->text);
	return (NULL);
}

int		init_threads(t_data *t, int i)
{
	pthread_t	thread;

	t->time = get_time();
	while (i < t->nb_of_philo)
	{
		t->phil[i].time = get_time();
		if (pthread_create(&thread, NULL, start_routine,
			(void*)&t->phil[i]))
			return (thread_create_failed(thread));
		pthread_detach(thread);
		if (pthread_create(&t->phil[i].thread, NULL,
			&check_if_dead, (void*)&t->phil[i]))
			return (thread_create_failed(thread));
		usleep(1000);
		i++;
	}
	i = 0;
	while (i < t->nb_of_philo)
	{
		if (pthread_join(t->phil[i].thread, NULL))
			return (thread_join_failed(t->phil[i].thread));
		i++;
	}
	return (0);
}
