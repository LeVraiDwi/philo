/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:53:16 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/13 14:54:47 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

pthread_mutex_t	**ft_create_fork(int nb_philo)
{
	int				i;
	pthread_mutex_t	**array_fork;

	i = 0;
	array_fork = (pthread_mutex_t **)
		malloc(sizeof(pthread_mutex_t *) * nb_philo);
	if (!array_fork)
		return (0);
	i = 0;
	while (i < nb_philo)
	{
		array_fork[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
		if (!array_fork[i])
			return (0);
		if (pthread_mutex_init(array_fork[i], 0))
			return (0);
		i++;
	}
	return (array_fork);
}

int	ft_create_philo(t_setting *setting,
		pthread_mutex_t **array_fork, t_philosophe **philo)
{
	int	i;

	i = 0;
	while (i < setting->time[0])
	{
		philo[i] = (t_philosophe *)malloc(sizeof(t_philosophe)
				* setting->time[0]);
		if (!*philo)
			return (ft_free_philo(i - 1, philo));
		if (!ft_init_philo(philo[i], setting, array_fork, i))
			return (0);
		i++;
	}
	return (1);
}

int	ft_set_table(t_setting *setting,
		t_philosophe ***philo, pthread_mutex_t ***array_fork)
{
	*array_fork = ft_create_fork(setting->time[0]);
	if (!*array_fork)
		return (ft_error(1));
	*philo = (t_philosophe **)malloc(sizeof(t_philosophe *) * setting->time[0]);
	if (!*philo)
	{
		ft_free_fork(setting->time[0], *array_fork);
		return (ft_error(2));
	}
	if (!ft_create_philo(setting, *array_fork, *philo))
	{
		ft_free_fork(setting->time[0], *array_fork);
		return (ft_error(2));
	}
	return (1);
}
