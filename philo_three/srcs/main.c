/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 11:41:13 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/28 10:51:55 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int		write_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (1);
}

void	init_semaphores(int n, t_data *t)
{
	sem_unlink(SEM_FORKS);
	t->lock_forks = sem_open(SEM_FORKS, O_CREAT, 0600, n);
	sem_unlink(SEM_TEXT);
	t->lock_text = sem_open(SEM_TEXT, O_CREAT, 0600, 1);
	sem_unlink(SEM_EAT);
	t->lock_eat = sem_open(SEM_EAT, O_CREAT, 0600, 1);
	sem_unlink(SEM_GEN);
	t->lock_gen = sem_open(SEM_GEN, O_CREAT, 0600, 0);
	t->thread = malloc(sizeof(pthread_t));
}

bool	check_arguments(char **argv, t_data *t)
{
	int	i;
	int	args[5];

	args[4] = -1;
	i = 1;
	while (argv[i])
	{
		args[i - 1] = ft_atoi(argv[i]);
		if (args[i - 1] == 0)
			return (true);
		i++;
	}
	t->nb_of_philo = args[0];
	t->time_die = args[1];
	t->time_eat = args[2];
	t->time_sleep = args[3];
	t->nb_of_meals = args[4];
	init_semaphores(args[0], t);
	return (false);
}

int		main(int argc, char **argv)
{
	t_data	t;
	int		ret;

	if (argc < 5 || argc > 6)
		return (write_error("Error: not right amount of arguments\n"));
	if (check_arguments(argv, &t))
		return (write_error("Error: wrong argument(s)\n"));
	ret = start_process(&t, 0);
	free(t.thread);
	return (ret);
}
