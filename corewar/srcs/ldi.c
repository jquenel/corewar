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
	int		reg[2];
	int		vpos;

	reg[0] = dtoi(args[2].data, args[2].size) - 1;
	if ((unsigned int)reg[0] > 15)
		return (0);
	if (args[0].type == T_REG)
	{
		reg[1] = dtoi(args[0].data, args[0].size) - 1;
		if ((unsigned int)reg[1] > 15)
			return (0);
		ft_memcpy(&args[0].data, actual->reg[reg[1]], REG_SIZE);
		args[0].size = REG_SIZE;
	}
	vpos = (core_getvalue(core, &args[0], actual) +
			core_getvalue(core, &args[1], actual)) % IDX_MOD;
	ft_memset(actual->reg[reg[0]], 0, REG_SIZE);
	copy_data(core, actual->reg[reg[0]], actual->pc + vpos, REG_SIZE);
	return (1);
}
