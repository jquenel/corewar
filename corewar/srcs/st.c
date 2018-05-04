/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/04 16:21:09 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_st(t_sen *core, t_bo *actual, t_arg *args)
{
	int		reg1;
	int		reg2;

	reg1 = dtoi(args[0].data, args[0].size) - 1;
	reg2 = dtoi(args[1].data, args[1].size) - (args[1].type == T_REG ? 1 : 0);
	if ((unsigned int)reg1 > 15 ||
			(args[1].type == T_REG && (unsigned int)reg2 > 15))
		return (1);
	if (args[1].type == T_REG)
	{
		ft_memset(actual->reg[reg2], 0, REG_SIZE);
		ft_memcpy(actual->reg[reg2], actual->reg[reg1], REG_SIZE);
	}
	else
	{
		core_regtomem(&core->arena, actual->reg[reg1],
				actual->pc + (reg2 % IDX_MOD),
				actual->pindex);
	}
	return (1);
}
