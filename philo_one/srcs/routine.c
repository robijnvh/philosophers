/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:29:51 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/21 14:35:55 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	ft_snooze(int i)
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

int		ft_eat(t_philo *p)
{
	// grab fork
	if (pthread_mutex_lock(&p->t->fork[p->fork_l]) == -1)
		return (1);
	if (pthread_mutex_lock(&p->t->fork[p->fork_r]) == -1)
		return (1);
	if (print(p, 1))
		return (1);
	if (print(p, 1))
		return (1);
	// start eating
	if (print(p, 2))
		return (1);
	p->time = get_time();
	if (pthread_mutex_lock(&p->eat) == -1)
		return (1);
	ft_snooze(p->t->time_eat);
	p->meals_eaten++;
	if (pthread_mutex_unlock(&p->eat) == -1)
		return (1);
	// drop fork
	if (pthread_mutex_unlock(&p->t->fork[p->fork_l]) == -1)
		return (1);
	if (pthread_mutex_unlock(&p->t->fork[p->fork_r]) == -1)
		return (1);
	return (0);
}

int		ft_sleep(t_philo *p)
{
	if (print(p, 3))
		return (1);
	ft_snooze(p->t->time_sleep);
	return (0);
}
