/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 13:10:43 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/28 10:47:03 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	exit_routine(pthread_t *thread, t_philo *p)
{
	free(thread);
	free(p);
	exit(2);
}

void	exit_routine_2(pthread_t *thread, t_philo *p)
{
	sem_post(p->p_lock_gen);
	free(thread);
	free(p);
	exit(2);
}

int		is_food_ready(t_philo *p, int n)
{
	if (sem_wait(p->p_lock_eat) == -1)
		return (2);
	if (n == 1)
	{
		p->last_meal = get_time();
		if (sem_post(p->p_lock_eat) == -1)
			return (2);
		return (1);
	}
	else
	{
		if (p->done == false && p->last_meal + p->t_die < get_time())
			return (1);
		if (sem_post(p->p_lock_eat) == -1)
			return (2);
		return (0);
	}
}

int		ft_eat(t_philo *p, t_data *t)
{
	// grab fork
	if (sem_wait(t->lock_forks) == -1)
		return (2);
	if (print(get_time(), 1, p))
		return (2);
	if (sem_wait(t->lock_forks) == -1)
		return (2);
	if (print(get_time(), 1, p))
		return (2);
	// start eating
	if (is_food_ready(p, 1) == 2)
		return (2);
	if (print(get_time(), 2, p))
		return (2);
	ft_snooze(p->t_eat);
	// drop fork
	if (sem_post(t->lock_forks))
		return (2);
	if (sem_post(t->lock_forks))
		return (2);
	return (0);
}

int		ft_sleep(t_philo *p)
{
	if (print(get_time(), 3, p))
		return (2);
	ft_snooze(p->t_sleep);
	return (0);
}
