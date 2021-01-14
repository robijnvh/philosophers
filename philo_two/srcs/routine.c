/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:29:51 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/14 11:06:14 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void		ft_fork(t_philo *p)
{
	sem_wait(p->t->lock_forks);
	sem_wait(p->t->lock_forks);
	print(p, 1);
	print(p, 1);
}

void		ft_drop_fork(t_philo *p)
{
	sem_post(p->t->lock_forks);
	sem_post(p->t->lock_forks);
}

void		ft_eat(t_philo *p)
{
	print(p, 2);
	p->time = get_time();
	sem_wait(p->lock_eat);
	usleep(p->t->nb_of_meals * 1000);
	p->meals_eaten++;
	sem_post(p->lock_eat);
}

void		ft_sleep(t_philo *p)
{
	print(p, 3);
	usleep(p->t->time_sleep * 1000);
}
