/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_getlvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:48:39 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/12 21:06:50 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"
#include "corewar.h"

static t_vect		*get_size(int len)
{
	int		i;
	int		j;

	i = get_root(len);
	j = i;
	while (i * j < len)
		i++;
	return (t_vect_new(i, j));
}

static void			define_base(t_visu *visu)
{
	int		i;
	int		j;

	i = get_win_size()->x / visu->tab_size->x;
	if (get_win_size()->y / visu->tab_size->y < i)
		i = get_win_size()->y / visu->tab_size->y;
	visu->space = i / 6;
	visu->unit = i - visu->space;
	i = (visu->unit + visu->space) * visu->tab_size->x + visu->space;
	j = (visu->unit + visu->space) * visu->tab_size->y + visu->space;
	visu->base_pos = t_vect_new((get_win_size()->x * 0.7) / 2 - i / 2,
									get_win_size()->y / 2 - j / 2);
	visu->zoom = 1;
	visu->font = NULL;
	set_texture_list(visu);
}

static void			define_str(t_visu *visu)
{
	visu->str_list[0] = "Live (10 cycles)";
	visu->str_list[1] = "Load (5 cycles)";
	visu->str_list[2] = "Store (5 cycles)";
	visu->str_list[3] = "Addition (10 cycles)";
	visu->str_list[4] = "Subtraction (10 cycles)";
	visu->str_list[5] = "Binary and (6 cycles)";
	visu->str_list[6] = "Binary or (6 cycles)";
	visu->str_list[7] = "Binary xor (6 cycles)";
	visu->str_list[8] = "Jump (20 cycles)";
	visu->str_list[9] = "Load index (25 cycles)";
	visu->str_list[10] = "Store index (25 cycles)";
	visu->str_list[11] = "Fork (800 cycles)";
	visu->str_list[12] = "Long load (10 cycles)";
	visu->str_list[13] = "Long load index (50 cycles)";
	visu->str_list[14] = "Long fork (1000 cycles)";
	visu->str_list[15] = "Aff (2 cycles)";
}

t_visu				*create_t_visu(t_sen *core)
{
	t_visu		*visu;

	if (!(visu = (t_visu *)malloc(sizeof(t_visu))))
		error_exit("Can't malloc a t_visu", 152);
	visu->field = core->arena.field;
	visu->pause = 1;
	visu->cycle_to_jump = 0;
	visu->index = core->arena.trace;
	visu->len = core->arena.size;
	visu->tab_size = get_size(visu->len);
	visu->p_color[0] = GREY;
	visu->p_color[1] = P1_COLOR;
	visu->p_color[2] = P2_COLOR;
	visu->p_color[3] = P3_COLOR;
	visu->p_color[4] = P4_COLOR;
	visu->music = Mix_LoadMUS(MUSIC_PATH);
	visu->end_sound = Mix_LoadWAV(END_SOUND);
	visu->select_proc = core->proc;
	define_base(visu);
	define_str(visu);
	visu->menu_font = TTF_OpenFont(FONT_PATH, visu->unit * 30);
	set_texture_menu_list(visu);
	visu->menu_font = TTF_OpenFont(FONT_PATH, visu->unit);
	return (visu);
}
