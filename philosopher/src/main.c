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
	t_setting	setting;

	ft_init_setting(&setting);
	if (ft_good_format(argc, argv, &setting))
	{
		ft_print(setting);	
	}
	else
		return (ft_error(0));
	return (1);
}
