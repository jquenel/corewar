/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:20:01 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/24 19:03:28 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
