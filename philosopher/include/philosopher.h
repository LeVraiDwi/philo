/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:34:39 by tcosse            #+#    #+#             */
/*   Updated: 2021/09/27 17:28:58 by tcosse           ###   ########.fr       */
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

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_setting
{
	int	time[5];
}				t_setting;

typedef struct s_philo
{
	int					death;
	int					name;
	pthread_t			thread;
	s_setting			*setting;
	t_fork				fork[2];
	struct timeval		start;
}

//error.c
int	ft_error(int c_error);
//parsing.c
int	ft_good_format(int argc, char **argv, t_setting *setting);
int	ft_isdigit(char c);
int ft_atoi(char *str);
int	ft_parsing(int argc, char **argv, t_setting *setting);
//struct.c
void	ft_init_setting(t_setting *setting);
#endif
