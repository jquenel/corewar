/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/04/23 17:09:42 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void corewar_st(t_sen *core, t_bo *actual, t_arg *args)
{
	int		value_size;
	int		reg1;
	int		reg2;

	reg1 = ft_convert(core, args[0].pos, args[0].size) - 1;
	reg2 = args[1].type == REG_CODE ?
		ft_convert(core, args[1].pos, args[1].size) - 1 :
		(actual->pc + (ft_convert(core, args[1].pos, args[1].size)
					   % IDX_MOD)) % core->arena.size;
	if ((unsigned int)reg1 > 15 ||
			(args[1].type == REG_CODE && (unsigned int)reg2 > 15))
		return (actual->carry);
	args[0].data = actual->reg[reg1];
	args[1].data = args[1].type == REG_CODE ? actual->reg[reg2] :
					&(core->arena.field[reg2]);
	if (args[1].type == REG_CODE)
		ft_memset(actual->reg[reg], 0, REG_SIZE);
	core_memcpy(core->arena, args[1], args[0], value_size);
	return (1);
}
