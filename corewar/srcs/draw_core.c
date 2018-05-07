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

static void		draw_cell(int i, int j, t_visu *visu)
{
	t_vect		coord;
	t_vect		size;
	int			pos;

	size.x = visu->unit * visu->zoom;
	size.y = visu->unit * visu->zoom;
	coord.x = (visu->base_pos->x + (i * (visu->unit + visu->space))
										+ visu->space / 2) * visu->zoom;
	coord.y = (visu->base_pos->y + (j * (visu->unit + visu->space))
										+ visu->space / 2) * visu->zoom;
	if (coord.x + (visu->unit * 2) * visu->zoom >= 0 && coord.x <
		get_win_size()->x && coord.y + visu->unit * visu->zoom >= 0 &&
		coord.y < get_win_size()->y)
	{
		pos = i + (j * visu->tab_size->x);
		draw_border_rectangle(&coord, &size, visu->p_color[(int)
														(visu->index[pos])]);
		coord.x = coord.x + (size.x / 2);
		coord.y = coord.y + (size.y / 2);
		draw_centred_sdltexture(visu->texture_list[
								(unsigned char)(visu->field[pos])], &coord, 0);
	}
}

void			draw_core(t_visu *visu)
{
	int			i;
	int			j;

	SDL_SetRenderDrawColor(get_renderer(), 40, 40, 40, 255);
	SDL_RenderClear(get_renderer());
	i = 0;
	while (i < visu->tab_size->x)
	{
		j = 0;
		while (j < visu->tab_size->y)
		{
			draw_cell(i, j, visu);
			j++;
		}
		i++;
	}
}
