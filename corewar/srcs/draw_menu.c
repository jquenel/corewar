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

static void		draw_player(t_visu *visu, t_vect *base, t_vect *menu_size,
																t_bushi *player)
{
	char		buffer[12];
	t_vect		size;
	t_vect		txt;
	t_vect		nbr;
	t_typo		typo;

	t_vect_actualize(&size, menu_size->x - visu->unit * 6, (visu->unit * 10));
	t_vect_actualize(&txt, base->x + visu->unit, base->y + visu->unit / 2);
	t_vect_actualize(&nbr, base->x + menu_size->x * 0.6,
													base->y + visu->unit / 2);
	draw_rectangle(base, &size, GREY);
	set_t_typo(&typo, "underline", visu->p_color[player->pindex],
															visu->menu_font);
	draw_text(player->name, &txt, &typo);
	draw_text(poor_itoa(player->pnum, buffer), &nbr, &typo);
	t_vect_actualize(&txt, txt.x, txt.y + visu->unit * 3);
	t_vect_actualize(&nbr, nbr.x, nbr.y + visu->unit * 3);
	draw_line("live last :", &txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(player->live_last, buffer), &nbr, visu, LIGHT_GREY);
	draw_line("live this period :", &txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(player->live, buffer), &nbr, visu, LIGHT_GREY);
	draw_line("nb_process :", &txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(player->proc_count, buffer), &nbr, visu, LIGHT_GREY);
	t_vect_actualize(base, base->x, base->y + visu->unit * 8);
}

static void		draw_cycles(t_sen *core, t_visu *visu, t_vect *txt,
															t_vect *menu_size)
{
	char		buffer[25];
	t_vect		nbr1;
	t_vect		nbr2;
	t_vect		nbr3;

	t_vect_actualize(&nbr1, txt->x + menu_size->x * 0.6, txt->y);
	t_vect_actualize(&nbr2, txt->x + menu_size->x * 0.7, txt->y +
																visu->unit * 2);
	t_vect_actualize(&nbr3, txt->x + menu_size->x * 0.75, txt->y +
																visu->unit * 2);
	draw_line("Cycles : ", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(core->state.c_total, buffer), &nbr1, visu, LIGHT_GREY);
	draw_line("Period : ", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(core->state.c_count, buffer), &nbr1, visu, LIGHT_GREY);
	draw_line(" / ", &nbr2, visu, LIGHT_GREY);
	draw_line(poor_itoa(core->state.c_todie, buffer), &nbr3, visu, LIGHT_GREY);
	draw_line("Cycles per second : ", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(get_fps(), buffer), &nbr1, visu, LIGHT_GREY);
}

void			draw_menu(t_sen *core, t_visu *visu, int cycles)
{
	int			i;
	t_vect		txt;
	t_vect		menu_size;

	t_vect_actualize(&txt, get_win_size()->x * 0.7, 0);
	t_vect_actualize(&menu_size, get_win_size()->x - txt.x,
													get_win_size()->y - txt.y);
	draw_rectangle(&txt, &menu_size, DARK_GREY);
	t_vect_actualize(&txt, txt.x + visu->unit, txt.y + visu->unit);
	draw_cycles(core, visu, &txt, &menu_size);
	i = 0;
	while (core->player[i].live != -2)
	{
		draw_player(visu, &txt, &menu_size, &(core->player[i]));
		t_vect_actualize(&txt, txt.x, txt.y + visu->unit * 3);
		i++;
	}
	(void)cycles;
}
