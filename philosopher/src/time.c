/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:53:33 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/05 16:19:17 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	gettimestamp(struct timeval timeval)
{
	struct timeval	time_act;
	long int		time;

	gettimeofday(&time_act, NULL);
	time = ((time_act.tv_sec - timeval.tv_sec) * 1000)
		+ ((time_act.tv_usec - timeval.tv_usec) / 1000);
	return (time);
}
