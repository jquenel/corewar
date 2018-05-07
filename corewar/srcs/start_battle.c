/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_battle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:48:51 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/07 17:26:19 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "template.h"

static int		do_cycle(t_sen *core, t_optab *op)
{
	int		cycles;

	if (core->opt & OPT_FAST)
	{
		if ((cycles = fast_cycle(core, op)) >= 0)
			return (cycles);
		if (core->opt & OPT_DUMP &&
			core->state.c_total - cycles >= core->state.dump_limit)
			dump_core(core);
		if (tsumego(core) < 1)
			return (-1);
		return (fast_cycle(core, op));
	}
	else
		return (cycle(core, op));
}

static void		draw_all(t_sen *core, t_visu *visu)
{
	draw_core(visu);
	draw_pc(core, visu);
	draw_menu(core, visu, core->state.c_count);
	draw_info(core, visu);
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
		draw_menu(core, visu, core->state.c_count);
		draw_info(core, visu);
		render_screen(visu->pause);
		update_input(visu);
	}
}

static t_visu	*init_visu(t_sen *core)
{
	t_visu		*visu;

	window_initialisation("char *window_name");
	visu = create_t_visu(core);
	return (visu);
}

void			start_battle(t_sen *core)
{
	int			alive;
	int			cycles;
	t_optab		op[OP_COUNT + 1];
	t_visu		*visu;

	init_optab(op);
	alive = 2;
	if (core->opt & OPT_VISU)
		visu = init_visu(core);
	while (alive)
	{
		if ((cycles = do_cycle(core, op)) < 0)
			break ;
		core->state.c_total += cycles;
		if (core->opt & OPT_DUMP &&
				core->state.c_total >= core->state.dump_limit)
			dump_core(core);
		core->state.c_count += cycles;
		if (core->state.c_count >= core->state.c_todie)
			alive = tsumego(core);
		if (core->opt & OPT_VISU)
			draw_corewar(core, visu);
	}
	declare_winner(core, visu);
}
