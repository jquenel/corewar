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

int			core_getlvalue(t_sen *core, t_arg *arg, t_bo *actual)
{
	if (arg->type == REG_CODE)
		return (core_regvalue(arg->data));
	if (arg->type == DIR_CODE)
		return (ft_convert(core, arg->data - FIELD, arg->size));
	return (ft_convert(core,
				((actual->pc +
				ft_convert(core, arg->data - FIELD, arg->size))
						% core->arena.size), DIR_SIZE));
}
