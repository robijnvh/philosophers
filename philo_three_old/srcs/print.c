/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:50:42 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/22 14:30:09 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

char	*set_name(char *str, int i)
{
	char	*tmp;
	char	*name;

	tmp = ft_itoa(i);
	name = ft_strjoin(str, tmp);
	free(tmp);
	return (name);
}

int		thread_create_failed(pthread_t thread)
{
	free(thread);
	write(2, "Error: pthread_create failed\n", 29);
	return (0);
}

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

void	write_text(t_philo *p, int i)
{
	char *tmp;

	tmp = text(i);
	write(1, "\e[90m", 5);
	ft_putnbr_fd(get_time() - p->t->time, 1);
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

int		print(t_philo *p, int i)
{
	if (sem_wait(p->t->lock_text) == -1)
		return (1);
	if (p->t->done != -1)
	{
		write_text(p, i);
		if (i == 5 || i == 6)
		{
			p->t->done = -1;
			return (0);
		}
	}
	if (sem_post(p->t->lock_text) == -1)
		return (1);
	return (0);
}
