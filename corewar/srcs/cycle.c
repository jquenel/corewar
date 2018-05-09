/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:46:56 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/09 21:36:17 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define SCHEDULED_NOW	core->schedule[core->state.c_total % MAX_OP_CYCLE]

int		cycle(t_sen *core, t_optab op[OP_COUNT + 1])
{
	while (SCHEDULED_NOW)
	{
		if (SCHEDULED_NOW->op)
			do_op(core, SCHEDULED_NOW);
		plan_op(core, SCHEDULED_NOW, op);
	}
	return (1);
}
