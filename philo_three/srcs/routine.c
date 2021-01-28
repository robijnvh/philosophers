/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 13:10:43 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/28 12:17:54 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	exit_routine(pthread_t *thread, t_philo *p, int sign)
{
	if (!sign)
		free(thread);
	if (sign == 1)
	{
		sem_post(p->p_lock_gen);
		free(thread);
	}
	free(p);
	exit(2);
}

int		is_food_ready(t_philo *p)
{
	if (sem_wait(p->p_lock_eat) == -1)
		return (2);
	if (p->done == false && p->last_meal + p->t_die < get_time())
		return (1);
	if (sem_post(p->p_lock_eat) == -1)
		return (2);
	return (0);
}

void	*check_if_dead(void *void_p)
{
	t_philo *p;

	p = (t_philo*)void_p;
	while (p->done == false)
	{
		if (is_food_ready(p))
		{
			p->last = 1;
			print(get_time(), 5, p);
			sem_post(p->p_lock_gen);
			return (NULL);
		}
	}
	return (NULL);
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
	if (sem_wait(p->p_lock_eat) == -1)
		return (2);
	p->last_meal = get_time();
	if (sem_post(p->p_lock_eat) == -1)
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
