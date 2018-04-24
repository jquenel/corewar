/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/04/24 23:26:52 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_st(t_sen *core, t_bo *actual, t_arg *args)
{
	int		value_size;
	int		reg1;
	int		reg2;

	value_size = REG_SIZE < DIR_SIZE ? REG_SIZE : DIR_SIZE;
	reg1 = ft_convert(core, args[0].data - FIELD, args[0].size) - 1;
	reg2 = args[1].type == REG_CODE ?
		ft_convert(core, args[1].data - FIELD, args[1].size) - 1 :
		(actual->pc + (ft_convert(core, args[1].data - FIELD, args[1].size)
					   % IDX_MOD)) % core->arena.size;
	if ((unsigned int)reg1 > 15 ||
			(args[1].type == REG_CODE && (unsigned int)reg2 > 15))
		return (0);
	args[0].data = actual->reg[reg1];
	args[1].data = args[1].type == REG_CODE ? actual->reg[reg2] :
															&(FIELD[reg2]);
	if (args[1].type == REG_CODE)
		ft_memset(actual->reg[reg2], 0, REG_SIZE);
	core_memcpy(&core->arena, &args[1], &args[0], value_size);
	return (1);
}
