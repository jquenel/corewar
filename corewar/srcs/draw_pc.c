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
#include "corewar.h"

static void		draw_pc_cell(int i, int j, t_visu *visu)
{
	t_vect	coord;
	int		pos;
	t_vect	size;

	t_vect_actualize(&size, (visu->unit) * visu->zoom, visu->unit * visu->zoom);
	coord.x = (visu->base_pos->x + (i * (visu->unit + visu->space)) +
												visu->space / 2) * visu->zoom;
	coord.y = (visu->base_pos->y + (j * (visu->unit + visu->space)) +
												visu->space / 2) * visu->zoom;
	if (coord.x + (visu->unit) * visu->zoom >= 0 && coord.x <
		get_win_size()->x && coord.y + visu->unit * visu->zoom >= 0 &&
		coord.y < get_win_size()->y)
	{
		pos = i + (j * visu->tab_size->x);
		draw_border_rectangle(&coord, &size,
									visu->p_color[(int)(visu->index[pos])] + 1);
		coord.x = coord.x + ((visu->unit / 2) * visu->zoom);
		coord.y = coord.y + ((visu->unit / 2) * visu->zoom);
		draw_centred_sdltexture(visu->texture_list[(unsigned char)
												(visu->field[pos])], &coord, 0);
	}
}
/*
static void		draw_selected_pc()
{
	t_visu *visu
}*/

void			draw_pc(t_sen *core, t_visu *visu)
{
	t_bo	*tmp;
	int		i;
	int		j;

	tmp = core->proc;
	while (tmp != NULL)
	{
		j = tmp->pc / visu->tab_size->y;
		i = tmp->pc - (j * visu->tab_size->x);
		draw_pc_cell(i, j, visu);
		tmp = tmp->next;
	}
}
