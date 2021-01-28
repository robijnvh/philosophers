/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_three.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 12:30:00 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/28 11:57:40 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <semaphore.h>
# include <stdbool.h>

# define SEM_FORKS "forks"
# define SEM_TEXT "text"
# define SEM_EAT "eat"
# define SEM_GEN "sem"

typedef	struct			s_philo
{
	int					t_die;
	int					t_sleep;
	int					t_eat;
	int					meals;
	int					next;
	int					last;
	int					nb;
	unsigned long int	time;
	unsigned long int	last_meal;
	bool				done;
	sem_t				*p_lock_gen;
	sem_t				*p_lock_eat;
	sem_t				*p_lock_text;
}						t_philo;

typedef struct			s_data
{
	int					nb_of_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					nb_of_meals;
	unsigned long int	time;
	int					*pid;
	pthread_t			*thread;
	sem_t				*lock_forks;
	sem_t				*lock_gen;
	sem_t				*lock_eat;
	sem_t				*lock_text;
	t_philo				*phil;
}						t_data;

int						start_process(t_data *t, int i);
int						is_food_ready(t_philo *p);
int						write_error(char *str);
void					set_data(t_data *t, t_philo *p, int i);
int						print(unsigned long time, int i, t_philo *p);
int						ft_eat(t_philo *p, t_data *t);
int						ft_sleep(t_philo *p);
unsigned long int		get_time(void);
void					ft_snooze(int i);
void					ft_snooze_nano(int i);
int						ft_atoi(const char *str);
void					exit_routine(pthread_t *thread, t_philo *p, int sign);
void					ft_putnbr_fd(int n, int fd);
size_t					ft_strlen(const char *str);
#endif
