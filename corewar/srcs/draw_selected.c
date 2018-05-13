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

static int		draw_line(char *text, t_vect *coord, t_visu *visu, int color)
{
	t_typo	typo;
	int		i;

	i = draw_text(text, coord, set_t_typo(&typo, "normal", color,
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
	draw_line("Live this turn :", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(visu->select_proc->live, buffer), &nbr, visu,
																	LIGHT_GREY);
	draw_line("Cycle left for the instruction :", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(visu->select_proc->cycle, buffer), &nbr, visu,
																	LIGHT_GREY);
}

static void		draw_registre_line(t_visu *visu, int base, t_vect *txt,
																t_vect *size)
{
	int			i;
	int			j;
	t_vect		coord;
	t_vect		txt_size;

	t_vect_actualize(&coord, txt->x - visu->unit / 3, txt->y);
	t_vect_actualize(&txt_size, size->x / 4, size->y);
	i = 0;
	while (i < 4)
	{
		draw_rectangle(&coord, size, LIGHT_GREY);
		j = 0;
		while (j < 4)
		{
			draw_sdltexture(visu->texture_menu_list[(int)(visu->select_proc->reg[base + i][j])], &coord, &txt_size, 0);
			t_vect_actualize(&coord, coord.x + txt_size.x, coord.y);
			j++;
		}
		t_vect_actualize(&coord, coord.x + visu->unit / 2, coord.y);
		i++;
	}
	t_vect_actualize(txt, txt->x, txt->y + size->y + visu->unit);
}

static void		draw_registre(t_visu *visu, t_vect *base, t_vect *menu_size)
{
	t_typo		typo;
	t_vect		size;
	int			i;

	t_vect_actualize(base, base->x + ((menu_size->x - visu->unit * 2) / 2),
													base->y + visu->unit * 1.5);
	draw_centred_text("-----REGISTRES-----", base,
				set_t_typo(&typo, "underline", LIGHT_GREY, visu->menu_font));
	t_vect_actualize(base, base->x - ((menu_size->x - visu->unit * 2) / 2),
													base->y + visu->unit * 1.5);
	t_vect_actualize(&size, (menu_size->x - (visu->unit * 4)) / 4,
						(get_win_size()->y - base->y - visu->unit * 8) / 4);
	i = 0;
	while (i < REG_NUMBER)
	{
		draw_registre_line(visu, i, base, &size);
		i += 4;
	}
}

void			draw_selected(t_visu *visu)
{
	t_vect		txt;
	t_vect		menu_size;
	t_vect		size;

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
