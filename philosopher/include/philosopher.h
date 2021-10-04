/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:34:39 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/04 17:08:25 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_setting
{
	int					end;
	long int			nb_finisheat;
	int					time[5];
	pthread_mutex_t		write;
	struct timeval		start;
}				t_setting;

typedef struct s_philosophe
{
	int					eat_time;
	int					name;
	pthread_t			thread;
	t_setting			*setting;
	t_fork				*fork[2];
	struct timeval		alive;
}				t_philosophe;

//error.c
int				ft_error(int c_error);
//parsing.c
int				ft_good_format(int argc, char **argv, t_setting *setting);
int				ft_isdigit(char c);
int				ft_atoi(char *str);
int				ft_parsing(int argc, char **argv, t_setting *setting);
//struct.c
int				ft_init_setting(t_setting *setting);
int				ft_init_fork(t_fork *fork);
void			ft_init_philo(t_philosophe *philo, t_setting *setting, t_fork *array_fork, int i);
//set_table.c
int				ft_create_fork(int nb_philo, t_fork **array_fork);
int				ft_create_philo(t_setting *setting, t_fork *array_fork, t_philosophe **philo);
int				ft_set_table(t_setting *setting, t_philosophe ***philo, t_fork ***array_fork);
//free_struct.c
int				ft_free_fork(int nb_philo, t_fork **array_fork);
int				ft_free_philo(int nb_philo, t_philosophe **philo);
int				ft_free_struct(t_setting setting, t_philosophe **philo, t_fork **array_fork);
//time.c
long int		gettimestamp(struct timeval);
//lunch.c
int				lunch_time(t_setting *setting, t_philosophe **philo);
//philo.c
void			ft_write(t_philosophe *philo, char *str);
int				ft_taking_fork(t_philosophe *philo);
int				ft_eating(t_philosophe *philo);
void			*ft_philo(void *data);
int				ft_sleeping(t_philosophe *philo);
#endif
