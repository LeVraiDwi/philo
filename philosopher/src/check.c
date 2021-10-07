/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:52:12 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/07 11:25:29 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_check(void *data)
{
	int				i;
	t_philosophe	**philo;

	philo = (t_philosophe **)data;
	while (1)
	{
		i = 0;
		while (i < philo[0]->setting->time[0])
		{
			if (!ft_check_philo(philo[i]))
				return (0);
			i++;
		}
	}
}

int	ft_check_philo(t_philosophe *philo)
{
	if (gettimestamp(philo->alive) >= philo->setting->time[1])
	{
		ft_write(philo, DIE);
		philo->setting->end = 1;
		return (0);
	}
	return (1);
}

void	ft_finish_eat(t_philosophe *philo)
{
	philo->setting->nb_finisheat++;
	if (philo->setting->nb_finisheat == philo->setting->time[0])
	{
		pthread_mutex_lock(&philo->setting->write);
		philo->setting->end = 1;
		pthread_mutex_unlock(&philo->setting->write);
	}
}
