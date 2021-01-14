/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 11:07:51 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/14 10:05:40 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

int		clean_all(t_data *t, int i)
{
	if (!t)
		return (0);
	// if (t->fork)
	{
		while (i < t->nb_of_philo)
		{
			// pthread_mutexattr_destroy((void*)&t->fork[i]);
			i++;
		}
		// free(t->fork);
	}
	// pthread_mutexattr_destroy((void*)&t->text);
	if (t->phil)
	{
		i = 0;
		while (i < t->nb_of_philo)
		{
			// pthread_mutexattr_destroy((void*)&t->phil[i].eat);
			i++;
		}
		free(t->phil);
		t->phil = NULL;
	}
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

int		init_philo(t_data *t)
{
	int	i;

	i = 0;
	if (!(t->phil = malloc(sizeof(t_data) * t->nb_of_philo)))
		return (2);
	while (i < t->nb_of_philo)
	{
		t->phil[i].nb = i;
		t->phil[i].meals_eaten = 0;
		t->phil[i].t = t;
		sem_unlink(ft_strjoin(SEM_EAT, ft_itoa(i)));
		t->lock_eat = sem_open(ft_strjoin(SEM_EAT, ft_itoa(i)), O_CREAT, 0644, 1);
		if (t->lock_eat == SEM_FAILED)
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
	return (init_philo(t));
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
		clean_all(&t, 0);
		return (0);
	}
	if (init_threads(&t))
	{
		clean_all(&t, 0);
		return (0);
	}
	clean_all(&t, 0);
	// while (1);  // check for leaks
	return (0);
}

