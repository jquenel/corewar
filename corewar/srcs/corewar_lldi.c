/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:12:21 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/09 22:42:55 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			corewar_lldi(t_sen *core, t_bo *actual, t_arg *args)
{
	int		vpos;
	int		is_reg[3];

	if (!get_regs(args, is_reg))
		return (1);
	vpos = core_getlvalue(core, &args[0], actual) +
			core_getlvalue(core, &args[1], actual);
	ft_memset(actual->reg[(int)(args[2].data[0])], 0, REG_SIZE);
	copy_data(core, actual->reg[(int)(args[2].data[0])], actual->pc + vpos,
																	REG_SIZE);
	if (core->opt & OPT_VERB)
		ft_printf("[%d][%d] lldi : %d.\n", actual->parent->pnum,
	actual->proc_num, dtoi(actual->reg[(int)(args[2].data[0])], REG_SIZE));
	return (1);
}
