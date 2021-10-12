/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:53:09 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/12 18:46:29 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_write(t_philosophe *philo, char *str)
{
	pthread_mutex_lock(&philo->setting->write);
	if (!philo->setting->end)
		printf("%.4ld %d %s\n",
			gettimestamp(philo->setting->start), philo->name, str);
	pthread_mutex_unlock(&philo->setting->write);
}

int	ft_taking_fork(t_philosophe *philo)
{
	pthread_mutex_lock(&philo->fork[0]->mutex);
	ft_write(philo, FORK);
	if (philo->setting->time[0] != 1)
		pthread_mutex_lock(&philo->fork[1]->mutex);
	else
	{
		while (!philo->setting->end)
		{
			usleep(10);
		}
		pthread_mutex_unlock(&philo->fork[0]->mutex);
	}
	ft_write(philo, FORK);
	return (1);
}

int	ft_sleeping(t_philosophe *philo)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	ft_write(philo, SLEEP);
	pthread_mutex_lock(&philo->setting->m_end);
	while (gettimestamp(start) < philo->setting->time[3]
		&& !philo->setting->end)
	{
		pthread_mutex_unlock(&philo->setting->m_end);
		pthread_mutex_lock(&philo->setting->m_end);
	}
	pthread_mutex_unlock(&philo->setting->m_end);
	return (1);
}

int	ft_eating(t_philosophe *philo)
{
	struct timeval	start;

	if (!philo->setting->end)
	{
		pthread_mutex_lock(&philo->m_alive);
		gettimeofday(&philo->alive, NULL);
		pthread_mutex_unlock(&philo->m_alive);
		gettimeofday(&start, NULL);
		philo->eat_time++;
		ft_write(philo, EAT);
		if (philo->eat_time == philo->setting->time[4])
			ft_finish_eat(philo);
		pthread_mutex_lock(&philo->setting->m_end);
		while ((gettimestamp(start)) < philo->setting->time[2]
			&& !philo->setting->end)
		{
			pthread_mutex_unlock(&philo->setting->m_end);
			pthread_mutex_lock(&philo->setting->m_end);
		}
		pthread_mutex_unlock(&philo->setting->m_end);
	}
	pthread_mutex_unlock(&philo->fork[0]->mutex);
	pthread_mutex_unlock(&philo->fork[1]->mutex);
	return (1);
}

void	*ft_philo(void *data)
{
	t_philosophe	*philo;

	philo = (t_philosophe *)data;
	pthread_mutex_lock(&philo->setting->m_end);
	while (!philo->setting->end)
	{
		pthread_mutex_unlock(&philo->setting->m_end);
		ft_taking_fork(philo);
		ft_eating(philo);
		ft_sleeping(philo);
		ft_write(philo, THINK);
		pthread_mutex_lock(&philo->setting->m_end);
	}
	pthread_mutex_unlock(&philo->setting->m_end);
	return (0);
}
