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
	struct timeval		time;

	if(!ft_init_setting(&setting))
		return (ft_error(1));
	array_fork = 0;
	philo = 0;
	if (ft_good_format(argc, argv, &setting))
	{
		if (!ft_set_table(setting, &philo, &array_fork))
			return (0);
		gettimeofday(&time, NULL);
		while (1)
		{
			usleep(500000);
			printf("time:%li\n", gettimestamp(time));
		}
//		if (!lunch_time(setting, philo))
		ft_free_struct(setting, philo, array_fork);
	}
	else
		return (ft_error(0));
	return (1);
}
