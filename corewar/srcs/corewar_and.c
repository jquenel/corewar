/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:54:09 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/06 20:33:27 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_and(t_sen *core, t_bo *actual, t_arg *args)
{
	int		value;
	int		dest;
	int		i;
	int		s[2];
	int		is_reg[3];

	if (!get_regs(args, is_reg))
		return (1);
	dest = (int)(args[2].data[0]);
	s[0] = 2;
	s[1] = s[0] + args[0].size;
	value = core_getvalue(core, &args[1], actual, actual->pc + s[0]) &
			core_getvalue(core, &args[2], actual, actual->pc + s[1]);
	i = REG_SIZE;
	while (i--)
		actual->reg[dest][REG_SIZE - i - 1] = ((char *)(&value))[i];
	actual->carry = dtoi(actual->reg[dest], REG_SIZE) == 0 ? 1 : 0;
	return (1);
}
