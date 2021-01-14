/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 11:07:51 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/14 11:33:10 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

int		clean_all(t_data *t)
{
	int	i;

	if (!t)
		return (0);
	i = 0;
	if (t->phil)
	{
		while (i < t->nb_of_philo)
		{
			sem_close(t->phil[i].lock_eat);
			sem_unlink(t->phil[i].name);
			free(t->phil[i].name);
			i++;
		}
		free(t->phil);
	}
	sem_close(t->lock_forks);
	sem_close(t->lock_text);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_TEXT);
	return (1);
}

int		get_time(void)
{
	struct timeval	tv;
	int				i;

	gettimeofday(&tv, NULL);
	i = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (i);
}

int		init_philo(t_data *t, int i, char *tmp)
{
	if (!(t->phil = malloc(sizeof(t_data) * t->nb_of_philo)))
		return (2);
	while (i < t->nb_of_philo)
	{
		t->phil[i].nb = i;
		t->phil[i].meals_eaten = 0;
		t->phil[i].t = t;
		tmp = ft_itoa(i);
		t->phil[i].name = ft_strjoin(SEM_EAT, tmp);
		free(tmp);
		sem_unlink(t->phil[i].name);
		t->phil[i].lock_eat = sem_open(t->phil[i].name, O_CREAT, 0644, 1);
		if (t->phil[i].lock_eat == SEM_FAILED)
			return (3);
		i++;
	}
	sem_unlink(SEM_FORKS);
	t->lock_forks = sem_open(SEM_FORKS, O_CREAT, 0644, t->nb_of_philo);
	if (t->lock_forks == SEM_FAILED)
		return (3);
	sem_unlink(SEM_TEXT);
	t->lock_text = sem_open(SEM_TEXT, O_CREAT, 0644, 1);
	if (t->lock_text == SEM_FAILED)
		return (3);
	return (0);
}

int		check_args(int argc, char **argv, t_data *t)
{
	if (argc < 5 || argc > 6)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (1);
	}
	t->nb_of_philo = ft_atoi(argv[1]);
	t->time_die = ft_atoi(argv[2]);
	t->time_eat = ft_atoi(argv[3]);
	t->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		t->nb_of_meals = ft_atoi(argv[5]);
	if (t->nb_of_philo < 1 || t->time_die < 0 || t->time_eat < 0
		|| t->time_sleep < 0 || (argc == 6 && t->nb_of_meals < 0))
	{
		write(2, "Wrong input\n", 12);
		return (1);
	}
	return (init_philo(t, 0, NULL));
}

int		main(int argc, char **argv)
{
	t_data	t;
	int		i;

	memset(&t, 0, sizeof(t_data));
	if ((i = check_args(argc, argv, &t)))
	{
		if (i == 2)
			write(2, "Error: Malloc failed\n", 21);
		if (i == 3)
			write(2, "Error: Semaphore failed\n", 24);
		clean_all(&t);
		return (0);
	}
	if (init_threads(&t))
	{
		clean_all(&t);
		return (0);
	}
	clean_all(&t);
	// while (1);  // check for leaks
	return (0);
}

