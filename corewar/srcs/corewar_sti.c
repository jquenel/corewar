/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_sti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:56:43 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/10 19:12:21 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			corewar_sti(t_sen *core, t_bo *actual, t_arg *args)
{
	int		vpos;
	int		is_reg[3];

	if (!get_regs(args, is_reg, 3))
		return (1);
	if (!is_reg[0])
		return (1);
	vpos = (core_getvalue(core, &args[1], actual) +
			core_getvalue(core, &args[2], actual)) % IDX_MOD;
	core_regtomem(&core->arena, actual->reg[(int)(args[0].data[0])],
				actual->pc + vpos, actual->parent->pindex);
	return (1);
}
