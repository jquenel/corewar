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

static void		draw_reg_number(t_visu *visu, int nbr, t_vect *coord,
																t_vect *size)
{
	char		buffer[12];
	int			len;
	t_typo		typo;

	draw_rectangle(coord, size, LIGHT_GREY);
	t_vect_actualize(coord, coord->x + visu->unit, coord->y - visu->unit / 6);
	len = draw_text(strange_poor_itoa(nbr + 1, buffer), coord,
						set_t_typo(&typo, BOLD, BLACK, visu->menu_font));
	t_vect_actualize(coord, coord->x + visu->unit * 2, coord->y);
	len = draw_text(" : ", coord, set_t_typo(&typo, NORMAL,
												BLACK, visu->menu_font));
	t_vect_actualize(coord, coord->x + len, coord->y);
}

static void		draw_reg_line(t_visu *visu, int base, t_vect *txt, t_vect *size)
{
	t_vect		pos;
	t_vect		coord;
	t_vect		size_image;

	t_vect_actualize(&coord, txt->x - visu->unit / 3, txt->y);
	t_vect_actualize(&size_image, visu->unit * 1.3, visu->unit * 1.4);
	pos.x = 0;
	while (pos.x < 2)
	{
		draw_reg_number(visu, base + pos.x, &coord, size);
		pos.y = 0;
		while (pos.y < 4)
		{
			draw_sdltexture(visu->texture_menu_list[(unsigned char)
				(visu->select_proc->reg[base + pos.x][pos.y])],
				&coord, &size_image, 0);
			t_vect_actualize(&coord, coord.x + size_image.x, coord.y);
			pos.y++;
		}
		pos.x++;
		t_vect_actualize(&coord, txt->x + (visu->unit * 13) * pos.x, coord.y);
	}
	t_vect_actualize(txt, txt->x, txt->y + size->y + visu->unit / 2);
}

void			draw_registre(t_visu *visu, t_vect *base, t_vect *menu_size)
{
	t_typo		typo;
	t_vect		size;
	int			i;

	t_vect_actualize(base, base->x + ((menu_size->x - visu->unit * 2) / 2),
													base->y + visu->unit * 1.5);
	draw_centred_text("-----REGISTRES-----", base,
				set_t_typo(&typo, UNDERLINE, LIGHT_GREY, visu->menu_font));
	if (!visu->select_proc)
		return ;
	t_vect_actualize(base, base->x - ((menu_size->x - visu->unit * 2) / 2),
													base->y + visu->unit * 1.5);
	t_vect_actualize(&size, (menu_size->x - (visu->unit * 4)) / 2,
						(get_win_size()->y - base->y - visu->unit * 8) / 6);
	i = 0;
	while (i < REG_NUMBER)
	{
		draw_reg_line(visu, i, base, &size);
		i += 2;
	}
}
