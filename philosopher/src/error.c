/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:09:15 by tcosse            #+#    #+#             */
/*   Updated: 2021/09/27 16:20:56 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_error(int c_error)
{
	if (c_error == 0)
		printf("Error:\nformat expect : ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]. il doit y avoir 1 philosophe minimun, Range : [0, %d]\n", MAX_INT);
	if (c_error == 1)
		printf("Error:\nErreur a l'allocation des fourchettes\n");
	if (c_error == 2)
		printf("Error:\nErreur a la creation des philosophe\n");
	return (0);
}
