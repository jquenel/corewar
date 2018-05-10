/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:20:01 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/10 21:01:22 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define FIELD_INDEX(x)		FIELD[(int)x % core->arena.size]
#define OP_BYTE				FIELD_INDEX(actual->pc)
#define CODE_BYTE			FIELD_INDEX(actual->pc + 1)

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
					actual->args[i].size);
		actual->size += actual->args[i].size;
		i++;
	}
}

static int	check_args_validity(t_bo *actual)
{
	int		i;

	i = actual->op->arg_count;
	while (i--)
	{
		if (!(actual->args[i].type & actual->op->arg_types[i]))
			return (0);
	}
	return (1);
}

void		do_op(t_sen *core, t_bo *actual)
{
	if (actual->op->extra & EX_CD)
		decode_types(core, actual);
	else
		input_types(core, actual);
	if (!check_args_validity(actual))
		actual->pc = (actual->pc + actual->size) % core->arena.size;
	else if (actual->op->op(core, actual, actual->args))
		actual->pc = (actual->pc + actual->size) % core->arena.size;
	actual->op = NULL;
}
