/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/09 22:41:28 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_ld(t_sen *core, t_bo *actual, t_arg *args)
{
	int		reg;
	int		vpos;

	reg = dtoi(args[1].data, args[1].size) - 1;
	if ((unsigned int)reg > REG_NUMBER)
		return (1);
	if (args[0].type == T_IND)
	{
		vpos = dtoi(args[0].data, args[0].size) % IDX_MOD;
		ft_memset(actual->reg[reg], 0, REG_SIZE);
		copy_data(core, actual->reg[reg], actual->pc + vpos, REG_SIZE);
	}
	else
	{
		ft_memset(actual->reg[reg], 0, REG_SIZE);
		ft_memcpy(actual->reg[reg], args[0].data,
				DIR_SIZE < REG_SIZE ? DIR_SIZE : REG_SIZE);
	}
	actual->carry = dtoi(actual->reg[reg], REG_SIZE) == 0 ? 1 : 0;
	if (core->opt & OPT_VERB)
		ft_printf("[%d][%d] ld : %d.\n", actual->parent->pnum,
		actual->proc_num, dtoi(actual->reg[reg], REG_SIZE));
	return (1);
}
