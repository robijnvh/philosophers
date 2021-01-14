/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_one.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robijnvanhouts <robijnvanhouts@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 11:06:48 by robijnvanho   #+#    #+#                 */
/*   Updated: 2021/01/14 10:17:53 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include "../../libft/libft.h"

typedef	struct		s_philo
{
	int				meals_eaten;
	int				nb;
	int				fork_l;
	int				fork_r;
	int				time;
	pthread_mutex_t	eat;
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
	pthread_mutex_t	*fork;
	pthread_mutex_t	text;
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
