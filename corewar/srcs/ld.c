/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/04/23 15:37:03 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void corewar_ld(t_sen *core, t_bo *actual, t_arg *args)
{
	int		value_size;
	int		reg;

	reg = ft_convert(core, args[1].pos, args[1].size) - 1;
	if ((unsigned int)reg > 15)
		return (0);
	value_size = args[0].size < REG_SIZE ? args[0].size : REG_SIZE;
	if (args[0].type == IND_CODE)
		args[0].pos = (actual->pc
			+ ft_convert(core, args[0].pos, args[0].size)) % IDX_MOD;
	ft_memset(actual->reg[reg], 0, REG_SIZE);
	ft_memcpy(actual->reg[reg], core->arena.field[(args[0].pos) % MEM_SIZE],
					value_size);
	return (1);
}
