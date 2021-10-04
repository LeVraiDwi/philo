/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:34:25 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/04 15:33:28 by tcosse           ###   ########.fr       */
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

	if(!ft_init_setting(&setting))
		return (ft_error(1));
	array_fork = 0;
	philo = 0;
	if (ft_good_format(argc, argv, &setting))
	{
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
