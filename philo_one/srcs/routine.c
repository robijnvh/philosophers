/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:29:51 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/14 14:21:44 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void		ft_snooze(int i)
{
	int		time;
	int		tmp;

	time = get_time();
	time = time + i;
	tmp = 0;
	while (tmp < time)
	{
		tmp = get_time();
		usleep(10);
	}
}

void		ft_eat(t_philo *p)
{
	// grab fork
	pthread_mutex_lock(&p->t->fork[p->fork_l]);
	pthread_mutex_lock(&p->t->fork[p->fork_r]);
	print(p, 1);
	print(p, 1);
	// start eating
	print(p, 2);
	p->time = get_time();
	pthread_mutex_lock(&p->eat);
	ft_snooze(p->t->time_eat);
	p->meals_eaten++;
	pthread_mutex_unlock(&p->eat);
	// drop fork
	pthread_mutex_unlock(&p->t->fork[p->fork_l]);
	pthread_mutex_unlock(&p->t->fork[p->fork_r]);
}

void		ft_sleep(t_philo *p)
{
	print(p, 3);
	ft_snooze(p->t->time_sleep);
}
