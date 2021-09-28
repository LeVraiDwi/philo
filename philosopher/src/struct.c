/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:09:27 by tcosse            #+#    #+#             */
/*   Updated: 2021/09/27 16:26:40 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_init_setting(t_setting *setting)
{
	int	i;

	i = 0;
	while (i < 5)
		setting->time[i++] = -1;
}

int	ft_init_fork(t_fork *fork)
{
	if(pthread_mutex_init(&fork->mutex, 0))
		return (0);
	return (1);
}

void	ft_init_philo(t_philosophe *philo, t_setting *setting, t_fork *array_fork, int i)
{
	philo->death = 0;
	philo->name = i + 1;
	philo->thread = 0;
	philo->setting = setting;
	philo->fork[0] = &array_fork[i];
	if (i + 1 == setting->time[0])
		philo->fork[1] = &array_fork[0];
	else
		philo->fork[1] = &array_fork[i + 1];
}
