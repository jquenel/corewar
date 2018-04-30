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
	int		reg;
	int		vpos;

	ft_printf("hello ld\n");
	reg = dtoi(args[1].data, args[1].size) - 1;
	if ((unsigned int)reg > REG_NUMBER)
		return (1);
	ft_printf("going to load in reg #%d\n", reg);
	if (args[0].type == T_IND)
	{
		vpos = dtoi(args[0].data, args[0].size) % IDX_MOD;
		ft_printf("loading indirect value at [%d] bytes from pc\n", vpos);
		ft_memset(actual->reg[reg], 0, REG_SIZE);
		copy_data(core, actual->reg[reg], actual->pc + vpos, REG_SIZE);
	}
	else
	{
		ft_printf("loading direct value\n");
		ft_memset(actual->reg[reg], 0, REG_SIZE);
		ft_memcpy(actual->reg[reg], args[0].data,
				DIR_SIZE < REG_SIZE ? DIR_SIZE : REG_SIZE);
	}
	actual->carry = dtoi(actual->reg[reg], REG_SIZE) == 0 ? 1 : 0;
	ft_printf("set reg #%d to value [%#.4x]\n", reg, dtoi(actual->reg[reg], REG_SIZE));
	return (1);
}
