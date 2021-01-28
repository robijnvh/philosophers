/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 12:27:34 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/27 14:05:39 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

char	*text(int i)
{
	if (i == 1)
		return (" has taken a fork\n");
	else if (i == 2)
		return (" is eating\n");
	else if (i == 3)
		return (" is sleeping\n");
	else if (i == 4)
		return (" is thinking\n");
	else if (i == 5)
		return (" has died\n\e[0m");
	return ("\e[91m\tEnough meals eaten\n\e[0m");
}

void	write_text(t_philo *p, int i, unsigned long time)
{
	char *tmp;

	tmp = text(i);
	write(1, "\e[90m", 5);
	ft_putnbr_fd(time - p->time, 1);
	write(1, "\e[0m", 4);
	if (i == 5)
		write(1, "\e[91m", 5);
	if (i != 6)
	{
		write(1, "\tPhilosopher ", 13);
		ft_putnbr_fd(p->nb + 1, 1);
	}
	write(1, tmp, ft_strlen(tmp));
	tmp = NULL;
}

int		print(unsigned long time, int i, t_philo *p)
{
	if (sem_wait(p->p_lock_text) == -1)
		return (2);
	write_text(p, i, time);
	if (p->last == 0)
		if (sem_post(p->p_lock_text) == -1)
			return (2);
	return (0);
}
