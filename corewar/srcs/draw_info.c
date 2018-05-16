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

static int	check_coord(t_visu *visu, t_vect *coord)
{
	t_vect size;

	(void)coord;
	t_vect_actualize(&size,
			visu->base_pos->x + (visu->space + visu->unit) * visu->tab_size->x,
			visu->base_pos->y + (visu->space + visu->unit) * visu->tab_size->y);
	if (coord->x >= 0 && coord->x < visu->tab_size->x &&
		coord->y >= 0 && coord->y < visu->tab_size->y)
		return (1);
	return (0);
}

void		draw_info(t_sen *core, t_visu *visu)
{
	t_typo	typo;
	t_vect	mpos;
	t_vect	size;
	t_vect	coord;
	char	c;

	SDL_GetMouseState(&(mpos.x), &(mpos.y));
	t_vect_actualize(&size, visu->unit * 18, visu->unit * 2);
	coord.x = (mpos.x - (visu->base_pos->x * visu->zoom)) /
									((visu->unit + visu->space) * visu->zoom);
	coord.y = (mpos.y - (visu->base_pos->y * visu->zoom)) /
									((visu->unit + visu->space) * visu->zoom);
	if (check_coord(visu, &coord) && mpos.x > visu->base_pos->x &&
										mpos.y > visu->base_pos->y)
	{
		c = core->arena.field[(coord.x + (coord.y * visu->tab_size->x))];
		if (c < OP_COUNT && c > 0)
		{
			t_vect_actualize(&mpos, mpos.x + visu->unit, mpos.y + visu->unit);
			draw_border_rectangle(&mpos, &size, GREY);
			t_vect_actualize(&mpos, mpos.x + size.x / 2, mpos.y + size.y / 2);
			draw_centred_text(visu->str_list[(int)c - 1], &mpos,
						set_t_typo(&typo, NORMAL, BLACK, visu->menu_font));
		}
	}
}
