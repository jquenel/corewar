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
	int		value_size;
	int		reg[3];

	if (!get_regs(core, args, reg))
		return (0);
	if (args[1].type == REG_CODE)
		args[1].data = actual->reg[reg[1]];
	if (args[2].type == REG_CODE)
		args[2].data = actual->reg[reg[2]];
	value_size = REG_CODE < DIR_CODE ? REG_CODE : DIR_CODE;
	args[1].data = FIELD + ((actual->pc +
				(core_getvalue(core, &args[1], actual) +
				core_getvalue(core, &args[2], actual)) % IDX_MOD)
				% core->arena.size);
	args[1].type = DIR_CODE;
	args[1].size = DIR_SIZE;
	core_memcpy(&core->arena, &args[1], &args[0], value_size);
	return (1);
}
