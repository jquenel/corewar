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

t_vect			*t_vect_new(int x, int y)
{
	t_vect *tmp;

	if (!(tmp = (t_vect *)malloc(sizeof(t_vect))))
		error_exit("Can't malloc a t_vect", 152);
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}

void			t_vect_free(t_vect *coord)
{
	free(coord);
}

void			t_vect_actualize(t_vect *coord, int new_x, int new_y)
{
	coord->x = new_x;
	coord->y = new_y;
}
