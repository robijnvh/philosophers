/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 11:41:13 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/28 11:42:06 by robijnvanho   ########   odam.nl         */
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

bool	check_arguments(char **argv, t_data *t, int argc)
{
	t->nb_of_meals = -1;
	t->nb_of_philo = ft_atoi(argv[1]);
	t->time_die = ft_atoi(argv[2]);
	t->time_eat = ft_atoi(argv[3]);
	t->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		t->nb_of_meals = ft_atoi(argv[5]);
	if (t->nb_of_philo < 1 || t->time_die < 0 || t->time_eat < 0
	|| t->time_sleep < 0 || (argc == 6 && t->nb_of_meals < 0))
		return (write_error("Error: wrong input\n"));
	init_semaphores(t->nb_of_philo, t);
	return (false);
}

int		main(int argc, char **argv)
{
	t_data	t;
	int		ret;

	if (argc < 5 || argc > 6)
		return (write_error("Error: not right amount of arguments\n"));
	if (check_arguments(argv, &t, argc))
		return (write_error("Error: wrong argument(s)\n"));
	ret = start_process(&t, 0);
	free(t.thread);
	return (ret);
}
