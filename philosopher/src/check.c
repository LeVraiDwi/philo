/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:52:12 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/12 18:29:01 by tcosse           ###   ########.fr       */
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
	pthread_mutex_lock(&philo->m_alive);
	if (gettimestamp(philo->alive) >= philo->setting->time[1])
	{
		pthread_mutex_unlock(&philo->m_alive);
		ft_write(philo, DIE);
		pthread_mutex_lock(&philo->setting->m_end);
		philo->setting->end = 1;
		pthread_mutex_unlock(&philo->setting->m_end);
		return (0);
	}
	pthread_mutex_unlock(&philo->m_alive);
	return (1);
}

void	ft_finish_eat(t_philosophe *philo)
{
	pthread_mutex_lock(&philo->setting->eat);
	philo->setting->nb_finisheat++;
	if (philo->setting->nb_finisheat == philo->setting->time[0])
	{
		pthread_mutex_lock(&philo->setting->write);
		pthread_mutex_lock(&philo->setting->m_end);
		philo->setting->end = 1;
		pthread_mutex_unlock(&philo->setting->m_end);
		pthread_mutex_unlock(&philo->setting->write);
	}
	pthread_mutex_unlock(&philo->setting->eat);
}
