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

static int	get_regs(t_arg *args, int *reg)
{
	int		i;

	i = 3;
	while (i--)
	{
		if (args[i].type == T_REG)
		{
			reg[i] = dtoi(args[i].data, args[i].size) - 1;
			if ((unsigned int)reg[i] > 15)
				return (0);
		}
		else
			reg[i] = -1;
	}
	return (reg[2] == -1 ? 0 : 1);
}

int		corewar_ldi(t_sen *core, t_bo *actual, t_arg *args)
{
	int		vpos;
	int		reg[3];
	int		s[2];

	if (!get_regs(args, reg))
		return (0);
	s[0] = 2;
	s[1] = s[0] + args[0].size;
	if (args[0].type == T_REG)
	{
		ft_memcpy(&args[0].data, actual->reg[reg[0]], REG_SIZE);
		args[0].size = REG_SIZE;
	}
	if (args[1].type == T_REG)
	{
		ft_memcpy(&args[1].data, actual->reg[reg[1]], REG_SIZE);
		args[1].size = REG_SIZE;
	}
	vpos = (core_getvalue(core, &args[0], actual->pc + s[0]) +
			core_getvalue(core, &args[1], actual->pc + s[1])) % IDX_MOD;
	ft_memset(actual->reg[reg[2]], 0, REG_SIZE);
	copy_data(core, actual->reg[reg[2]], actual->pc + vpos, REG_SIZE);
	return (1);
}
