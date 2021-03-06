/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_battle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:48:51 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/25 23:50:47 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "template.h"

static void		draw_all(t_sen *core, t_visu *visu)
{
	(void)core;
	draw_core(visu);
	draw_pc(core, visu);
	draw_menu(core, visu);
	draw_info(core, visu);
	draw_help(visu);
	render_screen(visu->pause);
}

static void		draw_corewar(t_sen *core, t_visu *visu)
{
	visu->one_cycle = 0;
	if (visu->cycle_to_jump < 2 && visu->pause == 0)
	{
		draw_all(core, visu);
		visu->cycle_to_jump += get_fps() / 60.0f;
	}
	else
		visu->cycle_to_jump -= 1.0f;
	update_input(core);
	while (visu->pause == 1 && !visu->one_cycle && visu->cycle_to_jump < 2)
	{
		draw_all(core, visu);
		render_screen(visu->pause);
		update_input(core);
	}
}

static t_visu	*init_visu(t_sen *core)
{
	t_visu		*visu;

	window_initialisation("corewar - esport ready");
	visu = create_t_visu(core);
	Mix_PlayMusic(visu->music, -1);
	sound_intro(core, visu);
	draw_corewar(core, visu);
	visu->pause = 1;
	return (visu);
}

static void		plan_all_op(t_sen *core, t_optab *op)
{
	t_bo		*tmp;

	tmp = core->proc;
	while (tmp)
	{
		tmp->cycle = plan_op(core, tmp, op);
		tmp = tmp->next;
	}
}

void			start_battle(t_sen *core)
{
	int			alive;

	core->visu = core->opt & OPT_VISU ? init_visu(core) : NULL;
	init_optab(core, core->visu, &(core->op));
	plan_all_op(core, core->op);
	alive = 2;
	while (alive > (core->opt & OPT_DETH ? 1 : 0))
	{
		if (core->opt & OPT_VISU)
			draw_corewar(core, core->visu);
		cycle(core, core->op);
		core->state.c_total++;
		core->state.c_count++;
		if (core->opt & OPT_DUMP &&
				core->state.c_total >= core->state.dump_limit)
			dump_core(core);
		if (core->state.c_count >= core->state.c_todie)
			alive = tsumego(core);
	}
	declare_winner(core, core->visu);
}
