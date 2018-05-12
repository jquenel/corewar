/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:03:49 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/10 19:16:12 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_mul(t_sen *core, t_bo *actual, t_arg *args)
{
	int		value;
	int		dest;
	int		i;
	int		is_reg[3];

	if (!get_regs(args, is_reg, 3))
		return (1);
	if (!is_reg[2])
		return (1);
	dest = (int)(args[2].data[0]);
	value = core_getvalue(core, &args[0], actual) *
			core_getvalue(core, &args[1], actual);
	i = REG_SIZE;
	while (i--)
		actual->reg[dest][REG_SIZE - i - 1] = ((char *)(&value))[i];
	actual->carry = dtoi(actual->reg[dest], REG_SIZE) == 0 ? 1 : 0;
	return (1);
}