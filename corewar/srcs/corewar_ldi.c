/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:58:20 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/06 20:28:46 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			corewar_ldi(t_sen *core, t_bo *actual, t_arg *args)
{
	int		vpos;
	int		s[2];
	int		is_reg[3];

	if (!get_regs(args, is_reg))
		return (1);
	if (!is_reg[2])
		return (1);
	s[0] = 2;
	s[1] = s[0] + args[0].size;
	vpos = (core_getvalue(core, &args[0], actual, actual->pc + s[0]) +
			core_getvalue(core, &args[1], actual, actual->pc + s[1])) % IDX_MOD;
	ft_memset(actual->reg[(int)(args[2].data[0])], 0, REG_SIZE);
	copy_data(core, actual->reg[(int)(args[2].data[0])], actual->pc + vpos,
																	REG_SIZE);
	return (1);
}
