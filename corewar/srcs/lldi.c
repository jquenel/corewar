/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:12:21 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:31:50 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_lldi(t_sen *core, t_bo *actual, t_arg *args)
{
	int		value_size;
	int		reg;
	int		vpos;

	reg = ft_convert(core, args[2].data - FIELD, args[2].size) - 1;
	if ((unsigned int)reg > 15)
		return (0);
	args[2].data = actual->reg[reg];
	value_size = DIR_SIZE < REG_SIZE ? DIR_SIZE : REG_SIZE;
	vpos = core_getlvalue(core, &args[0], actual) +
			core_getlvalue(core, &args[1], actual);
	args[0].data = FIELD + ((actual->pc + vpos) % core->arena.size);
	args[0].size = DIR_SIZE;
	args[0].type = DIR_CODE;
	ft_memset(actual->reg[reg], 0, REG_SIZE);
	core_memcpy(&core->arena, &args[2], &args[0], value_size);
	actual->carry = core_regvalue(args[2].data) == 0 ? 1 : 0;
	return (1);
}
