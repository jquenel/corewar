/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_battle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:48:51 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:53:49 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	do_cycle(t_sen *core, t_optab *op)
{
	if (core->opt & OPT_FAST)
		fast_cycle(core, op);
	else
		cycle(core, op);
}

static int	tsumego(t_sen *core)
{
	int		alive;

	alive = check_alive(core->player, &core->proc);
	core->state.c_count -= core->state.c_todie;
	if (core->state.l_count >= core->state.l_limit
			|| ++core->state.l_checks == core->state.l_checks_limit)
	{
		core->state.l_checks = 0;
		core->state.c_todie = core->state.c_todie -
			core->state.c_delta
			< 0 ? 0 : core->state.c_todie - core->state.c_delta;
	}
	core->state.l_count = 0;
	return (alive);
}

void		start_battle(t_sen *core)
{
	int			alive;
	int			cycles;
	t_optab		op[OP_COUNT + 1];

	init_optab(op);
	alive = 2;
	while (alive > 1)
	{
		cycles = do_cycle(core, op);
		if ((core->state.c_total += cycles) >= core->state.dump_limit
			&& core->opt & OPT_DUMP)
			dump_core(core);
		if ((core->state.c_count += cycles) >= core->state.c_todie)
			alive = tsumego(core);
	}
	declare_winner(core, alive);
}
