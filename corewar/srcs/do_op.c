/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:20:01 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/06 15:31:46 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	if (!check_args_validity(actual))
		actual->pc = (actual->pc + actual->size) % core->arena.size;
	else if (actual->op->op(core, actual, actual->args))
		actual->pc = (actual->pc + actual->size) % core->arena.size;
	actual->op = NULL;
}
