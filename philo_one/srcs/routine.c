/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:29:51 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/12 11:51:11 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void		ft_fork(t_philo *p)
{
	pthread_mutex_lock(&p->t->fork[p->fork_l]);
	print(p, 1);
	pthread_mutex_lock(&p->t->fork[p->fork_r]);
	print(p, 1);
}

void		ft_drop_fork(t_philo *p)
{
	pthread_mutex_unlock(&p->t->fork[p->fork_l]);
	pthread_mutex_unlock(&p->t->fork[p->fork_r]);
}

void		ft_eat(t_philo *p)
{
	print(p, 2);
	p->time = get_time();
	pthread_mutex_lock(&p->eat);
	usleep(p->t->nb_of_meals * 1000);
	p->meals_eaten++;
	pthread_mutex_unlock(&p->eat);
}

void		ft_sleep(t_philo *p)
{
	print(p, 3);
	usleep(p->t->time_sleep * 1000);
}
