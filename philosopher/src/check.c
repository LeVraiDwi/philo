/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:52:12 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/05 16:00:53 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_check(void *data)
{
	int				i;
	t_philosophe	**philo;
	int				done_eat;

	philo = (t_philosophe **)data;
	while (1)
	{
		done_eat = 0;
		i = 0;
		while (i < philo[0]->setting->time[0])
		{
			if (!ft_check_philo(philo[i], &done_eat))
				return (0);
			i++;
		}
		if (done_eat >= philo[0]->setting->time[0])
		{
			philo[0]->setting->end = 1;
			return (0);
		}
	}
}

int	ft_check_philo(t_philosophe *philo, int *done_eat)
{
	if (gettimestamp(philo->alive) >= philo->setting->time[1])
	{
		ft_write(philo, DIE);
		philo->setting->end = 1;
		return (0);
	}
	if (philo->setting->time[4] >= 0
		&& philo->eat_time >= philo->setting->time[4])
		*done_eat = *done_eat + 1;
	return (1);
}
