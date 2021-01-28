/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 11:07:51 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/28 11:22:32 by robijnvanho   ########   odam.nl         */
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

int		clean_all(t_data *t, char *name, int i)
{
	if (!t || t->done == 1)
		return (0);
	if (t->phil)
	{
		while (i < t->nb_of_philo)
		{
			name = set_name(SEM_GEN, i);
			sem_close(t->phil[i].gen_lock);
			sem_unlink(name);
			free(name);
			name = set_name(SEM_EAT, i);
			sem_close(t->phil[i].lock_eat);
			sem_unlink(name);
			free(name);
			kill(t->pid[i], SIGKILL);
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

int		set_semaphores(t_data *t, char *name, int i)
{
	name = set_name(SEM_EAT, i);
	sem_unlink(name);
	t->phil[i].lock_eat = sem_open(name, O_CREAT, 0644, 1);
	if (t->phil[i].lock_eat == SEM_FAILED)
	{
		free(name);
		return (3);
	}
	free(name);
	name = set_name(SEM_GEN, i);
	sem_unlink(name);
	t->phil[i].gen_lock = sem_open(name, O_CREAT, 0644, 1);
	if (t->phil[i].gen_lock == SEM_FAILED)
	{
		free(name);
		return (3);
	}
	free(name);
	return (0);
}

int		init_philo(t_data *t, int i)
{
	if (!(t->phil = malloc(sizeof(t_data) * t->nb_of_philo)))
		return (write_error("Error: malloc failed\n"));
	while (i < t->nb_of_philo)
	{
		t->phil[i].nb = i;
		t->phil[i].meals_eaten = 0;
		t->phil[i].t = t;
		if (set_semaphores(t, NULL, i) != 0)
			return (write_error("Error: semaphore failed\n"));
		i++;
	}
	sem_unlink(SEM_FORKS);
	t->lock_forks = sem_open(SEM_FORKS, O_CREAT, 0644, t->nb_of_philo);
	if (t->lock_forks == SEM_FAILED)
		return (write_error("Error: semaphore failed\n"));
	sem_unlink(SEM_TEXT);
	t->lock_text = sem_open(SEM_TEXT, O_CREAT, 0644, 1);
	if (t->lock_text == SEM_FAILED)
		return (write_error("Error: semaphore failed\n"));
	return (0);
}

int		check_arguments(int argc, char **argv, t_data *t)
{
	if (argc < 5 || argc > 6)
		return (write_error("Error: wrong number of arguments\n"));
	t->nb_of_philo = ft_atoi(argv[1]);
	t->time_die = ft_atoi(argv[2]);
	t->time_eat = ft_atoi(argv[3]);
	t->time_sleep = ft_atoi(argv[4]);
	t->nb_of_meals = -1;
	if (argc == 6)
		t->nb_of_meals = ft_atoi(argv[5]);
	if (t->nb_of_philo < 1 || t->time_die < 0 || t->time_eat < 0
		|| t->time_sleep < 0 || (argc == 6 && t->nb_of_meals < 0))
		return (write_error("Error: wrong input\n"));
	return (init_philo(t, 0));
}

int		main(int argc, char **argv)
{
	t_data	t;
	int		i;

	t.done = 0;
	if (!memset(&t, 0, sizeof(t_data)))
		return (write_error("Error: malloc failed\n"));
	if ((i = check_arguments(argc, argv, &t)))
	{
		clean_all(&t, NULL, 0);
		return (2);
	}
	start_process(&t, 0);
	clean_all(&t, NULL, 0);
	t.done = 1;
	// while (1);  // check for leaks
	return (0);
}
