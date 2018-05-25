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

static char		*create_str(t_sen *core, int i)
{
	char		*str;
	char		buffer[16];

	if (core->player[i].live == -2)
	{
		str = ft_strdup("Empty player slot");
		return (str);
	}
	str = ft_strdup("Player ");
	ft_stradd_back(&str, poor_itoa(core->player[i].pnum, buffer));
	ft_stradd_back(&str, " : ");
	ft_stradd_back(&str, core->player[i].name);
	return (str);
}

static void		create_area(t_visu *visu)
{
	int		i;
	t_vect	state;
	t_vect	coord;
	t_vect	size;

	t_vect_actualize(&state, 0, 0);
	t_vect_actualize(&size, get_win_size()->x / 2 - visu->unit * 4,
								get_win_size()->y / 2 - visu->unit * 4);
	i = 0;
	while (i < 4)
	{
		t_vect_actualize(&coord,
							visu->unit * 2 + (state.x * (size.x + visu->unit)),
							visu->unit * 2 + (state.y * (size.y + visu->unit)));
		draw_border_rectangle(&coord, &size, GREY, 20);
		t_vect_actualize(&state, (state.x == 0 ? 1 : 0),
								(state.x == 1 && state.y == 0 ? 1 : state.y));
		i++;
	}
	render_screen(1);
}

static void		draw_player(t_visu *visu, char *str, t_typo *typo,
															t_vect *state)
{
	t_vect	coord;
	t_vect	size;

	t_vect_actualize(&size, get_win_size()->x / 2 - visu->unit * 4,
								get_win_size()->y / 2 - visu->unit * 4);
	t_vect_actualize(&coord,
		visu->unit * 2 + (state->x * (size.x + visu->unit))
		+ size.x / 2, visu->unit * 2 + (state->y *
		(size.y + visu->unit)) + size.y / 2);
	draw_centred_alpha_text(str, &coord, typo, 255);
	free(str);
}

void			sound_intro(t_sen *core, t_visu *visu)
{
	int			i;
	t_vect		state;
	t_typo		typo;
	TTF_Font	*font;

	font = TTF_OpenFont(FONT_PATH, visu->unit * 3);
	t_vect_actualize(&state, 0, 0);
	i = 0;
	create_area(visu);
	update_input(core);
	while (i < 4)
	{
		set_t_typo(&typo, NORMAL,
			core->player[i].live != -2 ? visu->p_color[core->player[i].pindex]
			: 0, font);
		draw_player(visu, create_str(core, i), &typo, &state);
		render_screen(1);
		i += play_sound(1, (core->player[i].live != -2 ?
											core->player[i].comment : NULL));
		t_vect_actualize(&state, (state.x == 0 ? 1 : 0),
								(state.x == 1 && state.y == 0 ? 1 : state.y));
	}
}
