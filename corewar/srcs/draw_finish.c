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

#define NO_WINNER	"No winner today ! Next time, try using REAL champions ?"

static void		draw_rect_finish(t_visu *visu)
{
	t_vect		coord;
	t_vect		size;

	t_vect_actualize(&size, get_win_size()->x * SCREEN_RATIO_X - visu->unit * 4,
													get_win_size()->y / 3);
	t_vect_actualize(&coord, (get_win_size()->x * SCREEN_RATIO_X) / 2 -
								size.x / 2, get_win_size()->y / 2 - size.y / 2);
	draw_rectangle(&coord, &size, YELLOW);
	t_vect_actualize(&coord, coord.x + visu->unit / 2, coord.y +
															visu->unit / 2);
	t_vect_actualize(&size, size.x - visu->unit, size.y -
								visu->unit);
	draw_rectangle(&coord, &size, GREY);
}

static void		draw_winner(t_visu *visu, char *str)
{
	t_vect		coord;
	t_typo		typo;

	t_vect_actualize(&coord, (get_win_size()->x * SCREEN_RATIO_X) / 2,
								get_win_size()->y / 2 - visu->unit * 4);
	draw_centred_text(str, &coord, set_t_typo(&typo,
									NORMAL, LIGHT_GREY, visu->final_font));
	t_vect_actualize(&coord, coord.x, coord.y + visu->unit * 8);
	draw_centred_text("Press echap to close the program", &coord,
			set_t_typo(&typo, NORMAL, LIGHT_GREY, visu->final_font));
}

static char		*create_str(t_sen *core, int i)
{
	char		*str;
	char		buffer[16];

	if (core->state.l_last == core->arena.empty_char)
	{
		str = ft_strdup(NO_WINNER);
		return (str);
	}
	str = ft_strdup("Player ");
	ft_stradd_back(&str, poor_itoa(core->player[i].pnum, buffer));
	ft_stradd_back(&str, "(");
	ft_stradd_back(&str, core->player[i].name);
	ft_stradd_back(&str, ") won !");
	return (str);
}

void			draw_finish(t_visu *visu, t_sen *core, int i)
{
	int			alive;
	char		*str;
	Mix_Chunk	*intro;

	alive = 1;
	visu->final_font_size = (visu->unit * 3);
	visu->final_font = TTF_OpenFont(FONT_PATH, visu->final_font_size);
	TTF_SetFontStyle(visu->final_font, get_typo(NORMAL));
	str = create_str(core, i);
	intro = Mix_LoadWAV(core->player[i].comment);
	Mix_PlayChannel(1, intro, -1);
	while (alive)
	{
		draw_core(visu);
		final_draw_menu(core, visu);
		draw_info(core, visu);
		draw_rect_finish(visu);
		draw_winner(visu, str);
		render_screen(visu->pause);
		final_control(core, &alive);
	}
	free(str);
	exit_corewar(core);
}
