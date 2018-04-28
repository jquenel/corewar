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

	reg = dtoi(args[1].data, args[1].size) - 1;
	if ((unsigned int)reg > REG_NUMBER)
		return (0);
	if (args[0].type == T_IND)
	{
		vpos = ft_convert(args[0].data, args[0].size) % IDX_MOD;
		args[0].type = T_DIR;
		args[0].size = DIR_SIZE;
		copy_to_arg(core, &args[0], actual->pc + vpos);
	}
	ft_memset(actual->reg[reg], 0, REG_SIZE);
	ft_memcpy(actual->reg[reg], args[0].data,
				DIR_SIZE < REG_SIZE ? DIR_SIZE : REG_SIZE);
	actual->carry = dtoi(actual->reg[reg], REG_SIZE) == 0 ? 1 : 0;
	return (1);
}
