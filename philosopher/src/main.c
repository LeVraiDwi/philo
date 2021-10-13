/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:34:25 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/13 14:32:50 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_setting			setting;
	pthread_mutex_t		**array_fork;
	t_philosophe		**philo;

	if (!ft_init_setting(&setting))
		return (ft_error(1));
	array_fork = 0;
	philo = 0;
	if (ft_good_format(argc, argv, &setting))
	{
		if (setting.time[4] == 0)
			return (1);
		if (!ft_set_table(&setting, &philo, &array_fork))
			return (0);
		if (!lunch_time(&setting, philo))
			return (0);
		ft_free_struct(setting, philo, array_fork);
	}
	else
		return (ft_error(0));
	return (1);
}
