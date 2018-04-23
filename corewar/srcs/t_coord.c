/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/04 19:13:33 by jboissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

t_2d_coord	*t_2d_coord_new(int x, int y)
{
	t_2d_coord *tmp;

	if (!(tmp = (t_2d_coord *)malloc(sizeof(t_2d_coord))))
		error_exit("Can't malloc a t_2d_coord", 152);
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}

void t_2d_coord_free(t_2d_coord *coord)
{
	free(coord);
}

void t_2d_coord_actualize(t_2d_coord *coord, int new_x, int new_y)
{
	coord->x = new_x;
	coord->y = new_y;
}
