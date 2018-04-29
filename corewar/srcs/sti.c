/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:10:25 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:30:40 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_regs(t_sen *core, t_arg *args, int *reg)
{
	int		i;

	i = 3;
	while (i--)
	{
		if (args[i].type == REG_CODE)
		{
			reg[i] = ft_convert(core, args[i].data - FIELD, args[i].size) - 1;
			if ((unsigned int)reg[i] > 15)
				return (0);
		}
		else
			reg[i] = -1;
	}
	return (reg[0] == -1 ? 0 : 1);
}

int		corewar_sti(t_sen *core, t_bo *actual, t_arg *args)
{
	int		vpos;
	int		reg[3];

	if (!get_regs(core, args, reg))
		return (0);
	if (args[2].type == T_REG)
	{
		ft_memcpy(&args[2].data, actual->reg[reg[2]], REG_SIZE);
		args[2].size = REG_SIZE;
	}
	if (args[1].type == T_REG)
	{
		ft_memcpy(&args[1].data, actual->reg[reg[1]], REG_SIZE);
		args[1].size = REG_SIZE;
	}
	vpos = (core_getvalue(core, &args[2], actual) +
			core_getvalue(core, &args[1], actual)) % IDX_MOD;
	core_regtomem(&core->arena, actual->reg[reg[0]],
				actual->pc + vpos, REG_SIZE);
	return (1);
}
