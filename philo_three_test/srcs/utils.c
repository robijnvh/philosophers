/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 11:53:45 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/28 10:53:27 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

unsigned long int	get_time(void)
{
	struct timeval	tv;
	int				i;

	gettimeofday(&tv, NULL);
	i = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (i);
}

unsigned long int	get_time_nano(void)
{
	struct timeval		time;
	unsigned long int	now;

	gettimeofday(&time, NULL);
	now = time.tv_sec * 1000000;
	now += time.tv_usec;
	return (now);
}

void				ft_snooze_nano(int i)
{
	unsigned long	time;

	time = get_time_nano();
	while (get_time_nano() < time + i)
	{
		usleep(10);
	}
}

void				ft_snooze(int i)
{
	unsigned long	time;
	unsigned long	tmp;

	time = get_time();
	time = time + i;
	tmp = 0;
	while (tmp < time)
	{
		tmp = get_time();
		usleep(100);
	}
}

void				set_data(t_data *t, t_philo *p, int i)
{
	p->nb = i;
	p->done = false;
	p->t_die = t->time_die;
	p->t_eat = t->time_eat;
	p->t_sleep = t->time_sleep;
	p->meals = t->nb_of_meals;
	p->last_meal = get_time();
	p->time = t->time;
	if (p->nb == t->nb_of_philo - 1)
		p->next = 0;
	else
		p->next = p->nb + 1;
	p->last = 0;
}
