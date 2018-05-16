/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_battle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:48:51 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/11 16:49:02 by jquenel          ###   ########.fr       */
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
	if (visu->cycle_to_jump <= 0 && visu->pause == 0)
		draw_all(core, visu);
	else
		visu->cycle_to_jump--;
	update_input(visu);
	while (visu->pause == 1 && !visu->one_cycle && visu->cycle_to_jump <= 0)
	{
		if (visu->cycle_to_jump <= 0)
			draw_all(core, visu);
		else
			visu->cycle_to_jump--;
		render_screen(visu->pause);
		update_input(visu);
	}
}

static t_visu	*init_visu(t_sen *core)
{
	t_visu		*visu;

	window_initialisation("char *window_name");
	visu = create_t_visu(core);
	//Mix_PlayMusic(visu->music, -1);
	draw_corewar(core, visu);
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
	while (alive)
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
