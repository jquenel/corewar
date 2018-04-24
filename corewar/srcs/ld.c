/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/04/24 23:22:10 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_ld(t_sen *core, t_bo *actual, t_arg *args)
{
	int		value_size;
	int		reg;
	int		vpos;

	reg = ft_convert(core, args[1].data - FIELD, args[1].size) - 1;
	if ((unsigned int)reg > 15)
		return (0);
	args[1].data = actual->reg[reg];
	value_size = args[0].size < REG_SIZE ? args[0].size : REG_SIZE;
	if (args[0].type == IND_CODE)
	{
		vpos = args[0].data - FIELD;
		args[0].data = FIELD +
			(vpos + (ft_convert(core, vpos, args[0].size) % IDX_MOD))
			% core->arena.size;
		args[0].type = DIR_CODE;
		args[0].size = DIR_SIZE;
	}
	ft_memset(actual->reg[reg], 0, REG_SIZE);
	core_memcpy(&core->arena, &args[1], &args[0], value_size);
	actual->carry = core_regvalue(args[1].data) == 0 ? 1 : 0;
	return (1);
}
