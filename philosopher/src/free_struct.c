/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:52:32 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/13 14:53:53 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_free_fork(int nb_philo, pthread_mutex_t **array_fork)
{
	int	i;

	i = 0;
	while (i < nb_philo && array_fork != 0 && array_fork[i] != 0)
	{
		pthread_mutex_destroy(array_fork[i]);
		if (array_fork[i] != 0)
			free(array_fork[i]);
		i++;
	}
	if (array_fork != 0)
		free(array_fork);
	return (0);
}

int	ft_free_philo(int nb_philo, t_philosophe **philo)
{
	int	i;

	i = 0;
	if (!philo)
		return (0);
	while (i < nb_philo)
	{
		pthread_mutex_destroy(&philo[i]->m_alive);
		free(philo[i]);
		i++;
	}
	free(philo);
	return (0);
}

int	ft_free_struct(t_setting setting,
		t_philosophe **philo, pthread_mutex_t **array_fork)
{
	ft_free_fork(setting.time[0], array_fork);
	ft_free_philo(setting.time[0], philo);
	pthread_mutex_destroy(&setting.write);
	pthread_mutex_destroy(&setting.eat);
	pthread_mutex_destroy(&setting.m_end);
	return (0);
}
