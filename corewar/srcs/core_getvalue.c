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

int			core_getvalue(t_sen *core, t_arg *arg, t_bo *actual)
{
	if (arg->type == REG_CODE)
		return (core_regvalue(arg->data));
	if (arg->type == DIR_CODE)
		return (ft_convert(core, arg->data - FIELD, arg->size));
	return (ft_convert(core,
				((actual->pc +
				(ft_convert(core, arg->data - FIELD, arg->size) % IDX_MOD))
						% core->arena.size), DIR_SIZE));
}
