/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/04/23 19:45:29 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		corewar_sub(t_sen *core, t_bo *actual, t_arg *args)
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
	z = 0;
	reg[0] = core_regvalue(actual->reg[reg[0]]) -
			core_regvalue(actual->reg[reg[1]]);
	i = REG_SIZE;
	while (i--)
		actual->reg[reg[2]][i] = ((char *)(reg[0]))[i];
	return (1);
}
