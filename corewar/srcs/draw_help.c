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

	draw_text(text, coord, set_t_typo(&typo, NORMAL, color, visu->menu_font));
	t_vect_actualize(coord, coord->x, coord->y + visu->unit * 1.5);
}

static void		draw_help_text1(t_visu *visu, t_vect *coord)
{
	t_vect_actualize(coord, visu->unit, visu->unit);
	draw_line("Press P for pause / unpause", coord, visu, WHITE);
	t_vect_actualize(coord, visu->unit, coord->y + visu->unit);
	draw_line("Press J to jump 1000 cycles", coord, visu, WHITE);
	t_vect_actualize(coord, visu->unit, coord->y + visu->unit);
	draw_line("Press S to jump 1 cycle", coord, visu, WHITE);
	t_vect_actualize(coord, visu->unit, coord->y + visu->unit);
	draw_line("Press top arrow / down arrow to increase", coord, visu, WHITE);
	draw_line("or decrease the number of cycles per second", coord, visu,
																		WHITE);
	draw_line("by ten cycles per second", coord, visu, WHITE);
	t_vect_actualize(coord, visu->unit, coord->y + visu->unit);
	draw_line("Press left arrow / right arrow to increase", coord, visu,
																		WHITE);
	draw_line("or decrease the number of cycles per second", coord, visu,
																		WHITE);
	draw_line("by one cycle per second", coord, visu, WHITE);
	t_vect_actualize(coord, visu->unit, coord->y + visu->unit);
	draw_line("Press the num.pad 1 or 3 to swap to the next", coord, visu,
																		WHITE);
	draw_line("or previous processus on the memory, and", coord, visu, WHITE);
	draw_line("have some information about it in the", coord, visu, WHITE);
	draw_line("bottom-right corner of the screen", coord, visu, WHITE);
	t_vect_actualize(coord, visu->unit, coord->y + visu->unit);
}

static void		draw_help_text2(t_visu *visu, t_vect *coord)
{
	draw_line("Pass your mouse-cursor on a instruction", coord, visu, WHITE);
	draw_line("to have informations about it", coord, visu, WHITE);
	t_vect_actualize(coord, visu->unit, coord->y + visu->unit);
	draw_line("Use the mouse-wheel to zoom/ unzoom the screen", coord, visu,
																		WHITE);
	t_vect_actualize(coord, visu->unit, coord->y + visu->unit);
	draw_line("Use the left click to move the screen", coord, visu, WHITE);
	t_vect_actualize(coord, visu->unit, coord->y + visu->unit);
	draw_line("Press R to reset the screen", coord, visu, WHITE);
	t_vect_actualize(coord, visu->unit, coord->y + visu->unit);
}

void			draw_help(t_visu *visu)
{
	t_vect		coord;
	t_vect		size;
	t_typo		typo;

	t_vect_actualize(&coord, visu->unit, visu->unit);
	draw_line("Press F1 for help", &coord, visu, WHITE);
	if (visu->help == 1)
	{
		t_vect_actualize(&coord, 0, 0);
		t_vect_actualize(&size, visu->unit * 30, get_win_size()->y);
		draw_rectangle(&coord, &size, DARK_GREY);
		t_vect_actualize(&coord, visu->unit / 2, visu->unit / 2);
		t_vect_actualize(&size, visu->unit * 29, get_win_size()->y -
																	visu->unit);
		draw_rectangle(&coord, &size, GREY);
		draw_help_text1(visu, &coord);
		draw_help_text2(visu, &coord);
	}
}
