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

static void		special_control(t_visu *visu, int *alive)
{
	SDL_Event	event;

	if (SDL_PollEvent(&event) == 1)
	{
		if (event.type == SDL_QUIT)
			*alive = 0;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			*alive = 0;
		else if (event.type == SDL_MOUSEWHEEL)
		{
			if (event.wheel.y > 0)
				visu->zoom *= 1.1;
			else if (event.wheel.y < 0)
				visu->zoom *= 0.9;
			set_texture_list(visu);
		}
		if (event.type == SDL_MOUSEMOTION &&
			event.button.button == SDL_BUTTON_LEFT)
		{
			visu->base_pos->x += event.motion.xrel;
			visu->base_pos->y += event.motion.yrel;
		}
	}
}

static void		draw_rect_finish(t_visu *visu)
{
	t_vect		coord;
	t_vect		size;

	t_vect_actualize(&size, get_win_size()->x - (visu->unit * 8),
													get_win_size()->y / 3);
	t_vect_actualize(&coord, get_win_size()->x / 2 - size.x / 2,
								get_win_size()->y / 2 - size.y / 2);
	draw_rectangle(&coord, &size, YELLOW);
	t_vect_actualize(&coord, coord.x + visu->unit / 2, coord.y +
															visu->unit / 2);
	t_vect_actualize(&size, size.x - visu->unit, size.y -
								visu->unit);
	draw_rectangle(&coord, &size, GREY);
}

static void		draw_winner(t_visu *visu, t_sen *core, char *str)
{
	t_vect		coord;
	t_typo		typo;

	t_vect_actualize(&coord, get_win_size()->x / 2,
								get_win_size()->y / 2 - visu->unit * 4);
	draw_centred_text(str, &coord, set_t_typo(&typo,
									NORMAL, LIGHT_GREY, visu->final_font));
	t_vect_actualize(&coord, coord.x, coord.y + visu->unit * 8);
	draw_centred_text("Press echap to close the program", &coord, set_t_typo(&typo,
									NORMAL, LIGHT_GREY, visu->final_font));
}


void			draw_finish(t_visu *visu, t_sen *core, int i)
{
	t_vect		coord;
	t_vect		size;
	int			alive;
	char		*str;
	char		buffer[16];

	alive = 1;
	visu->final_font_size = (visu->unit * 3);
	visu->final_font = TTF_OpenFont(FONT_PATH, visu->final_font_size);
	TTF_SetFontStyle(visu->final_font, get_typo(NORMAL));
	str = ft_strdup("Player ");
	ft_stradd_back(&str, poor_itoa(core->player[i].pnum, buffer));
	ft_stradd_back(&str, "(");
	ft_stradd_back(&str, core->player[i].name);
	ft_stradd_back(&str, ") won !");
	while (alive)
	{
		draw_core(visu);
		final_draw_menu(core, visu);
		draw_info(core, visu);
		draw_rect_finish(visu);
		draw_winner(visu, core, str);
		special_control(visu, &alive);
		render_screen(visu->pause);
	}
}
