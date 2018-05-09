/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:38:28 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/09 23:55:24 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define FIELD_INDEX(x)		FIELD[(int)x % core->arena.size]
#define OP_BYTE				FIELD_INDEX(actual->pc)
#define CODE_BYTE			FIELD_INDEX(actual->pc + 1)
#define SCHEDULED_CYCLE(x)	core->schedule[(x) % MAX_OP_CYCLE]
#define PCYCLE				(actual->op ? actual->op->cycle : 1)

static void	input_types(t_sen *core, t_bo *actual)
{
	int		i;

	i = 0;
	actual->size = 1;
	while (i < actual->op->arg_count)
	{
		actual->args[i].type = actual->op->arg_types[i];
		if (actual->args[i].type == T_REG)
			actual->args[i].size = 1;
		else if (actual->args[i].type == T_DIR)
			actual->args[i].size = actual->op->extra & EX_IS ?
										IND_SIZE : DIR_SIZE;
		else if (actual->args[i].type == T_IND)
			actual->args[i].size = IND_SIZE;
		copy_data(core, actual->args[i].data, actual->pc + actual->size,
					actual->args[i].size);
		actual->size += actual->args[i].size;
		i++;
	}
}

static void	set_arg_attr(t_arg *arg, int type, int size)
{
	arg->type = type;
	arg->size = size;
}

static void	decode_types(t_sen *core, t_bo *actual)
{
	int		i;
	int		t;

	i = 0;
	actual->size = 2;
	while (i < actual->op->arg_count)
	{
		t = (FIELD_INDEX(actual->pc + 1) >> ((MAX_ARGS_NUMBER - 1 - i) * 2))
			& 0x3;
		if (t == REG_CODE)
			set_arg_attr(&actual->args[i], T_REG, 1);
		else if (t == DIR_CODE)
			set_arg_attr(&actual->args[i], T_DIR, actual->op->extra & EX_IS ?
												IND_SIZE : DIR_SIZE);
		else if (t == IND_CODE)
			set_arg_attr(&actual->args[i], T_IND, IND_SIZE);
		else
			actual->args[i].type = 0;
		copy_data(core, actual->args[i].data, actual->pc + actual->size,
					actual->args[i].size); //this line goes in do_op now ?
		actual->size += actual->args[i].size;
		i++;
	}
}

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
	if (actual->op->extra & EX_CD)
		decode_types(core, actual);
	else
		input_types(core, actual);
	schedule_proc(core, actual);
	return (1);
}
