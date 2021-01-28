/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_three.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 12:30:00 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/28 11:03:16 by robijnvanho   ########   odam.nl         */
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

# define SEM_FORKS "forks"
# define SEM_TEXT "text"
# define SEM_EAT "eat"
# define SEM_GEN "sem"

typedef	struct		s_philo
{
	int				meals_eaten;
	int				nb;
	int				done;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				rounds;
	unsigned long int				last_eat;
	int				next;
	int				last;
	int				time;
	pid_t			pid;
	sem_t			*lock_eat;
	sem_t			*gen_lock;
	sem_t			*alive;
	struct s_data	*t;
}					t_philo;

typedef struct		s_data
{
	int				nb_of_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_of_meals;
	int				time;
	int				done;
	int				cnt;
	int				*pid;
	pthread_t		*thread;
	t_philo			*phil;
	sem_t			*lock_forks;
	sem_t			*lock_text;
	sem_t			*gen_lock;
	sem_t			*alive;
	pid_t			pid_data;
}					t_data;

int					get_time(void);
int					start_process(t_data *t, int i);
int					thread_create_failed(pthread_t thread);
int					print(t_philo *p, int i);
int					ft_eat(t_philo *p);
int					ft_sleep(t_philo *p);
int					clean_all(t_data *t, char *name, int i);
char				*set_name(char *str, int i);
int					get_time(void);
// utils
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
size_t				ft_strlen(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putnbr_fd(int n, int fd);

#endif
