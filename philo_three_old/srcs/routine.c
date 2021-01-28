/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:29:51 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/28 11:12:26 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

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
	if (sem_wait(p->t->lock_forks) == -1)
		return (1);
	if (print(p, 1))
		return (1);
	if (sem_wait(p->t->lock_forks) == -1)
		return (1);
	if (print(p, 1))
		return (1);
	// start eating
	if (print(p, 2))
		return (1);
	p->time = get_time();
	if (sem_wait(p->lock_eat) == -1)
		return (1);
	ft_snooze(p->t->time_eat);
	p->meals_eaten++;
	if (sem_post(p->lock_eat) == -1)
		return (1);
	if (sem_post(p->gen_lock) == -1)
		return (1);
	// drop fork
	if (sem_post(p->t->lock_forks) == -1)
		return (1);
	if (sem_post(p->t->lock_forks) == -1)
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
