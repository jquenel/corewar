/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:33:00 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:28:15 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_and(t_sen *core, t_bo *actual, t_arg *args)
{
	int		reg[3];
	int		i;

	reg[0] = ft_convert(core, args[0].data - FIELD, args[0].size) - 1;
	reg[1] = ft_convert(core, args[1].data - FIELD, args[1].size) - 1;
	reg[2] = ft_convert(core, args[2].data - FIELD, args[2].size) - 1;
	if ((unsigned int)reg[0] > REG_NUMBER ||
		(unsigned int)reg[1] > REG_NUMBER ||
		(unsigned int)reg[2] > REG_NUMBER)
		return (0);
	reg[0] = core_regvalue(actual->reg[reg[0]]) &
			core_regvalue(actual->reg[reg[1]]);
	i = REG_SIZE;
	while (i--)
		actual->reg[reg[2]][i] = ((char *)(&reg[0]))[i];
	actual->carry = core_regvalue(actual->reg[reg[2]]) == 0 ? 1 : 0;
	return (1);
}
