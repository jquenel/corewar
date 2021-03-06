/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/17 19:50:51 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_sub(t_sen *core, t_bo *actual, t_arg *args)
{
	int		value[3];
	int		dest;
	int		i;
	int		is_reg[3];

	if (!get_regs(args, is_reg, 3))
		return (1);
	if (!is_reg[2])
		return (1);
	dest = (int)(args[2].data[0]);
	value[0] = core_getvalue(core, &args[0], actual);
	value[1] = core_getvalue(core, &args[1], actual);
	value[2] = value[0] - value[1];
	i = REG_SIZE;
	while (i--)
		actual->reg[dest][REG_SIZE - i - 1] = ((char *)(&value[2]))[i];
	actual->carry = dtoi(actual->reg[dest], REG_SIZE) == 0 ? 1 : 0;
	if (core->opt & OPT_VERB)
		ft_printf("[PID :: %p]\t[ sub ]\t\t:\t(r%d)(%.8x) -"
				" (r%d)(%.8x) ---> (r%d)(%.8x))\n", actual,
		(int)(args[0].data[0]) + 1, value[0],
		(int)(args[1].data[0]) + 1, value[1],
		(int)(args[2].data[0]) + 1, value[2]);
	return (1);
}
