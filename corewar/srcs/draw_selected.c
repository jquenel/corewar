/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/17 13:11:56 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"
#include "corewar.h"

static int		draw_line(char *text, t_vect *coord, t_visu *visu, int color)
{
	t_typo	typo;
	int		i;

	i = draw_text(text, coord, set_t_typo(&typo, NORMAL, color,
															visu->menu_font));
	t_vect_actualize(coord, coord->x, coord->y + visu->unit * 2);
	return (i);
}

static void		draw_pc_info(t_visu *visu, t_vect *txt, t_vect *menu_size)
{
	char		buffer[12];
	int			i;
	t_vect		nbr;

	t_vect_actualize(txt, txt->x + visu->unit, txt->y + visu->unit);
	t_vect_actualize(&nbr, txt->x + menu_size->x * 0.6, txt->y);
	i = draw_line("Parent :", txt, visu, LIGHT_GREY);
	t_vect_actualize(&nbr, txt->x + i + visu->unit, txt->y - visu->unit * 2);
	draw_line(visu->select_proc->parent->name, &nbr, visu,
							visu->p_color[visu->select_proc->parent->pindex]);
	t_vect_actualize(&nbr, txt->x + menu_size->x * 0.6, txt->y);
	draw_line("Carry statement:", txt, visu, LIGHT_GREY);
	draw_line((visu->select_proc->carry == 0 ? "Disable" : "Enable"), &nbr,
															visu, LIGHT_GREY);
	draw_line("PC :", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(visu->select_proc->pc, buffer), &nbr, visu, LIGHT_GREY);
	draw_line("Lives this turn :", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(visu->select_proc->live, buffer), &nbr, visu,
																	LIGHT_GREY);
	draw_line("Cycles left :", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(visu->select_proc->cycle + 1, buffer), &nbr, visu,
																	LIGHT_GREY);
}

void			draw_selected(t_visu *visu)
{
	t_vect		txt;
	t_vect		menu_size;
	t_vect		size;

	t_vect_actualize(&txt, get_win_size()->x * 0.8 + visu->unit, 0 +
										(visu->unit * 7) + (visu->unit * 44));
	t_vect_actualize(&menu_size, get_win_size()->x - txt.x,
													get_win_size()->y - txt.y);
	t_vect_actualize(&size, menu_size.x - visu->unit, menu_size.y - visu->unit);
	draw_rectangle(&txt, &size, GREY);
	draw_pc_info(visu, &txt, &menu_size);
	draw_registre(visu, &txt, &menu_size);
}
