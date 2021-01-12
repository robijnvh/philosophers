/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:50:42 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/12 12:01:59 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int		ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
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
	return ("\e[91m\tLimit of meals reached\n\e[0m");
}

void	print(t_philo *p, int i)
{
	char	*tmp;

	pthread_mutex_lock(&p->t->text);
	if (!p->t->done)
	{
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
		if (i == 5 || i == 6)
		{
			p->t->done = 1;
			return ;
		}
	}
	pthread_mutex_unlock(&p->t->text);
}
