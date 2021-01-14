/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_two.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 12:30:00 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/14 10:20:35 by robijnvanho   ########   odam.nl         */
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
# include "../../libft/libft.h"

# define SEM_FORKS "forks"
# define SEM_TEXT "text"
# define SEM_EAT "eat"

typedef	struct		s_philo
{
	int				meals_eaten;
	int				nb;
	int				time;
	struct s_data	*t;
	pthread_t		thread;
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
	sem_t			*lock_eat;
	sem_t			*lock_text;
}					t_data;

int					get_time(void);
int					init_threads(t_data *t);
void				print(t_philo *p, int i);
void				ft_fork(t_philo *p);
void				ft_drop_fork(t_philo *p);
void				ft_eat(t_philo *p);
void				ft_sleep(t_philo *p);
int					clean_all(t_data *t, int i);

#endif
