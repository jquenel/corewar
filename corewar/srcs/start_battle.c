/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_battle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:48:51 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/06 15:16:01 by jquenel          ###   ########.fr       */
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
		if (tsumego(core) < 2)
			return (-1);
		return (fast_cycle(core, op));
	}
	else
		return (cycle(core, op));
}

static void		draw_corewar(t_sen *core, t_core *sdl_core)
{
	draw_core(sdl_core);
	draw_pc(core, sdl_core);
	draw_players(core, sdl_core, core->state.c_count);
	render_screen();
	update_input(sdl_core);
}

static t_core	*init_visu(t_sen *core)
{
	t_core		*sdl_core;

	window_initialisation("char *window_name");
	sdl_core = create_t_core(core);
	return (sdl_core);
}

void			start_battle(t_sen *core)
{
	int			alive;
	int			cycles;
	t_optab		op[OP_COUNT + 1];
	t_core		*sdl_core;

	init_optab(op);
	alive = 2;
	if (core->opt & OPT_VISU)
		sdl_core = init_visu(core);
	while (alive > 1)
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
			draw_corewar(core, sdl_core);
	}
	declare_winner(core, alive);
}
