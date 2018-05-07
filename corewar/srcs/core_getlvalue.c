/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_getlvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:48:39 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/07 16:57:00 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			core_getlvalue(t_sen *core, t_arg *arg, t_bo *actual)
{
	int		vpos;

	if (arg->type == T_REG)
		return (dtoi(actual->reg[(int)(arg->data[0])], REG_SIZE));
	if (arg->type == T_IND)
	{
		vpos = dtoi(arg->data, arg->size);
		arg->type = T_DIR;
		arg->size = DIR_SIZE;
		copy_data(core, arg->data, actual->pc + vpos, arg->size);
	}
	return (dtoi(arg->data, arg->size));
}
