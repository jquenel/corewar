/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:38:28 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/12 19:58:14 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline char	op_byte(t_sen *core, t_bo *actual)
{
	return (core->arena.field[actual->pc]);
}

int					plan_op(t_sen *core, t_bo *actual,
							t_optab op[OP_COUNT + 1])
{
	if (op_byte(core, actual) < 1 || op_byte(core, actual) >
			((core->opt & OPT_INST) ? BONUS_OP_COUNT : OP_COUNT))
	{
		actual->pc = (actual->pc + 1) % core->arena.size;
		actual->op = NULL;
		return (0);
	}
	ft_memset(actual->args, 0, sizeof(t_arg) * (MAX_ARGS_NUMBER));
	actual->op = &op[(int)op_byte(core, actual) - 1];
	return (actual->op->cycle - 1);
}
