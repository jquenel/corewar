/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:58:20 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/17 19:39:10 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			corewar_ldi(t_sen *core, t_bo *actual, t_arg *args)
{
	int		vpos;
	int		is_reg[3];

	if (!get_regs(args, is_reg, 3))
		return (1);
	if (!is_reg[2])
		return (1);
	vpos = (core_getvalue(core, &args[0], actual) +
			core_getvalue(core, &args[1], actual)) % IDX_MOD;
	ft_memset(actual->reg[(int)(args[2].data[0])], 0, REG_SIZE);
	copy_data(core, actual->reg[(int)(args[2].data[0])], actual->pc + vpos,
																	REG_SIZE);
	if (core->opt & OPT_VERB)
		ft_printf("[PID :: %p]\t[ ldi ]\t\t:\t(pc(%d) + %d)(%.8x)--->(r%d)\n",
		actual, actual->pc, vpos,
		core_getvalue(core, &args[2], actual), (int)(args->data[2]) + 1);
	return (1);
}
