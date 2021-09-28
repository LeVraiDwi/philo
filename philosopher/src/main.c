/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:34:25 by tcosse            #+#    #+#             */
/*   Updated: 2021/09/27 16:54:49 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void ft_print(t_setting setting)
{
	int	i;
	
	i = 0;
	while (i < 5)
	{
		printf("time:%d\n", setting.time[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_setting			setting;
	t_fork				**array_fork;
	t_philosophe		**philo;

	ft_init_setting(&setting);
	array_fork = 0;
	philo = 0;
	if (ft_good_format(argc, argv, &setting))
	{
		array_fork = (t_fork **)malloc(sizeof(t_fork *) * setting.time[0]);
		if (!array_fork)
			return (ft_error(1));
		if (!ft_create_fork(setting.time[0], array_fork))
			return (ft_error(1));
		printf("setting out:%d\n", setting.time[0]);
		philo = (t_philosophe **)malloc(sizeof(t_philosophe *) * setting.time[0]);
		if (!philo)
			return (ft_error(1));
		if (!ft_create_philo(setting, *array_fork, philo))
			return(ft_error(2));
		printf("fin\n");
	}
	else
		return (ft_error(0));
	return (1);
}
