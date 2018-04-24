/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:58:20 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:29:12 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_ldi(t_sen *core, t_bo *actual, t_arg *args)
{
	int		value_size;
	int		reg;
	int		vpos;

	reg = ft_convert(core, args[2].data - FIELD, args[2].size) - 1;
	if ((unsigned int)reg > 15)
		return (0);
	args[2].data = actual->reg[reg];
	value_size = DIR_SIZE < REG_SIZE ? DIR_SIZE : REG_SIZE;
	vpos = (core_getvalue(core, &args[0], actual) +
			core_getvalue(core, &args[1], actual)) % IDX_MOD;
	args[0].data = FIELD + ((actual->pc + vpos) % core->arena.size);
	args[0].size = DIR_SIZE;
	args[0].type = DIR_CODE;
	ft_memset(actual->reg[reg], 0, REG_SIZE);
	core_memcpy(&core->arena, &args[2], &args[0], value_size);
	return (1);
}
