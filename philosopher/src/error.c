/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:09:15 by tcosse            #+#    #+#             */
/*   Updated: 2021/10/05 15:59:46 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_error(int c_error)
{
	if (c_error == 0)
		printf(ERROR, MAX_INT);
	if (c_error == 1)
		printf("Error:\nErreur a l'allocation des fourchettes\n");
	if (c_error == 2)
		printf("Error:\nErreur a la creation des philosophe\n");
	return (0);
}
