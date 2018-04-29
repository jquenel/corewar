/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_getvalue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:21:09 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:11:33 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			core_getvalue(t_sen *core, t_arg *arg, int pc)
{
	int		vpos;

	if (arg->type == T_IND)
	{
		vpos = dtoi(arg->data, arg->size) % IDX_MOD;
		arg->type = T_DIR;
		arg->size = DIR_SIZE;
		copy_data(core, arg->data, pc + vpos, arg->size);
	}
	return (dtoi(arg->data, arg->size));
}
