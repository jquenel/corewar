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

static void		draw_line(char *text, t_vect *coord, t_visu *visu, int color)
{
	t_typo	typo;

	draw_text(text, coord, set_t_typo(&typo, "normal", color, visu->menu_font));
	t_vect_actualize(coord, coord->x, coord->y + visu->unit * 2);
}

static void		draw_pc_info(t_visu *visu, t_vect *txt, t_vect *menu_size)
{
	char		buffer[12];
	t_vect		nbr;

	t_vect_actualize(txt, txt->x + visu->unit, txt->y + visu->unit);
	t_vect_actualize(&nbr, txt->x + menu_size->x * 0.6, txt->y);

	draw_line("Parent :", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(1, buffer), &nbr, visu, LIGHT_GREY);
	draw_line("Carry statement:", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(2, buffer), &nbr, visu, LIGHT_GREY);
	draw_line("PC :", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(3, buffer), &nbr, visu, LIGHT_GREY);
	draw_line("Live this turn :", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(4, buffer), &nbr, visu, LIGHT_GREY);
	draw_line("Cycle left for the instruction :", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(5, buffer), &nbr, visu, LIGHT_GREY);
}

static void		draw_registre(t_visu *visu, t_vect *base, t_vect *menu_size)
{
	char		buffer[12];
	t_typo		typo;
	t_vect		coord;
	t_vect		tmp;
	int			i;

	t_vect_actualize(base, base->x + ((menu_size->x - visu->unit * 2) / 2),
													base->y + visu->unit * 1.5);
	draw_centred_text("-----REGISTRES-----", base, set_t_typo(&typo, "underline",
								LIGHT_GREY, visu->menu_font));
	t_vect_actualize(base, base->x - ((menu_size->x - visu->unit * 2) / 2),
													base->y + visu->unit * 1.5);
	t_vect_actualize(&tmp, (menu_size->x - (visu->unit * 12)) / 4,
						(get_win_size()->y - base->y - visu->unit * 8) / 4);
	i = 0;
	while (i < REG_NUMBER)
	{
		t_vect_actualize(&coord, base->x + (menu_size->x / 4 * (i % 4)),
					base->y + ((get_win_size()->y - base->y) / 4) * (i / 4));
		draw_border_rectangle(&coord, &tmp, GREY);
		t_vect_actualize(&coord, coord.x + tmp.x / 2, coord.y + tmp.y / 2);
		draw_centred_text(poor_itoa(i, buffer), &coord, set_t_typo(&typo, "normal",
									BLACK, visu->menu_font));
		i++;
	}
}

void			draw_selected(t_sen *core, t_visu *visu)
{
	t_vect		txt;
	t_vect		menu_size;
	t_vect		size;

	(void)core;
	t_vect_actualize(&txt,
					get_win_size()->x * 0.8 + visu->unit,
					0 + (visu->unit  * 7) + (visu->unit * 44));
	t_vect_actualize(&menu_size, get_win_size()->x - txt.x,
													get_win_size()->y - txt.y);
	t_vect_actualize(&size, menu_size.x - visu->unit, menu_size.y - visu->unit);
	draw_rectangle(&txt, &size, GREY);

	draw_pc_info(visu, &txt, &menu_size);

	draw_registre(visu, &txt, &menu_size);
}
