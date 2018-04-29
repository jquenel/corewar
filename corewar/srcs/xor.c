/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:37:29 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:28:40 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_xor(t_sen *core, t_bo *actual, t_arg *args)
{
	int		reg[3];
	int		i;

	(void)core;
	reg[0] = dtoi(args[0].data, args[0].size) - 1;
	reg[1] = dtoi(args[1].data, args[1].size) - 1;
	reg[2] = dtoi(args[2].data, args[2].size) - 1;
	if ((unsigned int)reg[0] > REG_NUMBER ||
		(unsigned int)reg[1] > REG_NUMBER ||
		(unsigned int)reg[2] > REG_NUMBER)
		return (1);
	reg[0] = dtoi(actual->reg[reg[0]], REG_SIZE) ^
			dtoi(actual->reg[reg[1]], REG_SIZE);
	i = REG_SIZE;
	while (i--)
		actual->reg[reg[2]][i] = ((char *)(&reg[0]))[i];
	actual->carry = dtoi(actual->reg[reg[2]], REG_SIZE) == 0 ? 1 : 0;
	return (1);
}
