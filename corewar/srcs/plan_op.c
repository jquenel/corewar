/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:38:28 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/10 21:39:03 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define FIELD_INDEX(x)		FIELD[(int)x % core->arena.size]
#define OP_BYTE				FIELD_INDEX(actual->pc)
#define CODE_BYTE			FIELD_INDEX(actual->pc + 1)

int			plan_op(t_sen *core, t_bo *actual, t_optab op[OP_COUNT + 1])
{
	if (OP_BYTE < 1
		|| OP_BYTE > ((core->opt & OPT_INST) ? BONUS_OP_COUNT : OP_COUNT))
	{
		actual->pc = (actual->pc + 1) % core->arena.size;
		actual->op = NULL;
		return (core->opt & OPT_FAST ? 1 : 0);
	}
	ft_memset(actual->args, 0, sizeof(t_arg) * (MAX_ARGS_NUMBER));
	actual->op = &op[(int)OP_BYTE - 1];
	return (actual->op->cycle - 1);
}
