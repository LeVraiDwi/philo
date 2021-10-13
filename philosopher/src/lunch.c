/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:52:41 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/13 13:04:57 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_launch_philo(t_philosophe **philo)
{
	int	i;

	i = 0;
	while (i < philo[0]->setting->time[0])
	{	
		philo[i]->name = i + 1;
		gettimeofday(&philo[i]->alive, NULL);
		if (pthread_create(&philo[i]->thread, 0, ft_philo, (void *)philo[i]))
			return (0);
		i++;
	}
	return (1);
}

int	lunch_time(t_setting *setting, t_philosophe **philo)
{
	int			i;
	int			j;
	pthread_t	thread;

	i = 0;
	j = 0;
	if (gettimeofday(&philo[0]->setting->start, NULL) == -1)
		return (0);
	setting->end = 0;
	if (!ft_launch_philo(philo))
		return (0);
	if (pthread_create(&thread, 0, ft_check, (void *)philo))
		return (0);
	if (pthread_detach(thread))
		return (0);
	i = 0;
	while (i < philo[0]->setting->time[0])
	{
		if (pthread_join(philo[i]->thread, NULL))
			return (1);
		i++;
	}
	return (1);
}
