/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:38:28 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/10 00:11:08 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define FIELD_INDEX(x)		FIELD[(int)x % core->arena.size]
#define OP_BYTE				FIELD_INDEX(actual->pc)
#define CODE_BYTE			FIELD_INDEX(actual->pc + 1)
#define SCHEDULED_CYCLE(x)	core->schedule[(x) % MAX_OP_CYCLE]
#define PCYCLE				(actual->op ? actual->op->cycle : 1)

static void	schedule_proc(t_sen *core, t_bo *actual)
{
	t_bo	*tmp;

	tmp = SCHEDULED_CYCLE(core->state.c_total + PCYCLE);
	if (!tmp)
	{
		SCHEDULED_CYCLE(core->state.c_total + PCYCLE) = actual;
		actual->next = NULL;
		actual->prev = NULL;
	}
	else
	{
		while (tmp && tmp->next && tmp->proc_num > actual->proc_num)
			tmp = tmp->next;
		if (tmp->proc_num > actual->proc_num)
		{
			actual->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = actual;
			tmp->next = actual;
			actual->prev = tmp;
		}
		else
		{
			actual->next = tmp;
			actual->prev = tmp->prev;
			if (tmp->prev)
				tmp->prev->next = actual;
			tmp->prev = actual;
			if (tmp == SCHEDULED_CYCLE(core->state.c_total + PCYCLE))
				SCHEDULED_CYCLE(core->state.c_total + PCYCLE) = actual;
		}
	}
}

int			plan_op(t_sen *core, t_bo *actual, t_optab op[OP_COUNT + 1])
{
	if (actual->next)
	{
		actual->next->prev = NULL;
		SCHEDULED_CYCLE(core->state.c_total) = actual->next;
	}
	else if (SCHEDULED_CYCLE(core->state.c_total) == actual)
		SCHEDULED_CYCLE(core->state.c_total) = NULL;
	ft_memset(actual->args, 0, sizeof(t_arg) * (MAX_ARGS_NUMBER));
	actual->prev = NULL;
	actual->next = NULL;
	if (OP_BYTE < 1 || OP_BYTE > OP_COUNT)
	{
		actual->pc = (actual->pc + 1) % core->arena.size;
		actual->op = NULL;
		schedule_proc(core, actual);
		return (0);
	}
	actual->op = &op[(int)OP_BYTE - 1];
	schedule_proc(core, actual);
	return (1);
}
