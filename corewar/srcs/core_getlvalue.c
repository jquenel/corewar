/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_getlvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:48:39 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:11:45 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			core_getlvalue(t_sen *core, t_arg *arg, int pc)
{
	int		vpos;

	if (arg->type == t_IND)
	{
		vpos = dtoi(arg->data, arg->size);
		arg->type = T_DIR;
		arg->size = DIR_SIZE;
		copy_to_arg(core, arg, pc + vpos);
	}
	return (dtoi(arg->data, arg->size);
}
