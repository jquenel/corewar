/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:58:43 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/24 19:03:10 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			set_arg_attr(t_arg *arg, int type, int size)
{
	arg->type = type;
	arg->size = size;
}

static inline char	field_index(t_sen *core, int index)
{
	return (core->arena.field[index % core->arena.size]);
}

void				decode_types(t_sen *core, t_bo *actual)
{
	int		i;
	int		t;

	i = 0;
	actual->size = 2;
	while (i < actual->op->arg_count)
	{
		t = (field_index(core, actual->pc + 1) >>
			((MAX_ARGS_NUMBER - 1 - i) * 2)) & 0x3;
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
