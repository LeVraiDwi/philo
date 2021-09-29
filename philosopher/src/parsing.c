/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:09:21 by tcosse            #+#    #+#             */
/*   Updated: 2021/09/27 16:27:17 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_good_format(int argc, char **argv, t_setting *setting)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (0);
	else 
	{
		if (!ft_parsing(argc, argv, setting))
			return (0);
	}
	if (setting->time[0] <= 0)
		return (0);
	return (1);
}

int ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	long	n;
	int		i;
	int		l;

	n = 0;
	i = 0;
	l = 0;
	if (!str || !*str)
		return (-1);	
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	while (l < i)
	{	
		n = n * 10;
		n += str[l++] - '0';
	}
	if (n > MAX_INT || n < MIN_INT)
		return (-1);
	return ((int)n);
}

int	ft_parsing(int argc, char **argv, t_setting *setting)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		setting->time[i - 1] = ft_atoi(argv[i]);
		if (setting->time[i - 1] < 0)
			return (0);
		i++;
	}
	return (1);
}
