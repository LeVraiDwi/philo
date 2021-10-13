/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:09:27 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/13 14:55:14 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_init_setting(t_setting *setting)
{
	int	i;

	i = 0;
	while (i < 5)
		setting->time[i++] = -1;
	if (pthread_mutex_init(&setting->write, 0))
		return (0);
	if (pthread_mutex_init(&setting->eat, 0))
		return (0);
	if (pthread_mutex_init(&setting->m_end, 0))
		return (0);
	setting->end = 0;
	setting->nb_finisheat = 0;
	return (1);
}

int	ft_init_philo(t_philosophe *philo,
		t_setting *setting, pthread_mutex_t **array_fork, int i)
{
	philo->name = i + 1;
	philo->thread = 0;
	philo->eat_time = 0;
	philo->setting = setting;
	if (pthread_mutex_init(&philo->m_alive, 0))
		return (0);
	philo->fork[0] = array_fork[i];
	if (i + 1 == setting->time[0])
		philo->fork[1] = array_fork[0];
	else
		philo->fork[1] = array_fork[i + 1];
	return (1);
}
