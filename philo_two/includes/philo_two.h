/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_two.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 12:30:00 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/22 13:53:19 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

# define SEM_FORKS "forks"
# define SEM_TEXT "text"
# define SEM_EAT "eat"

typedef	struct		s_philo
{
	char			*name;
	int				meals_eaten;
	int				nb;
	int				time;
	struct s_data	*t;
	pthread_t		thread;
	sem_t			*lock_eat;
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
	t_philo			*phil;
	sem_t			*lock_forks;
	sem_t			*lock_text;
}					t_data;

int					get_time(void);
int					init_threads(t_data *t, int i);
int					thread_join_failed(pthread_t thread);
int					thread_create_failed(pthread_t thread);
int					print(t_philo *p, int i);
int					ft_eat(t_philo *p);
int					ft_sleep(t_philo *p);
int					clean_all(t_data *t);
// utils
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
size_t				ft_strlen(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putnbr_fd(int n, int fd);

#endif
