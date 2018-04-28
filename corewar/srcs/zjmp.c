/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:38:37 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 19:58:11 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_zjmp(t_sen *core, t_bo *actual, t_arg *args)
{
	if (actual->carry != 1)
		return (0);
	actual->pc = (actual->pc +
				(dtoi(args[0].data, DIR_SIZE) % IDX_MOD))
				% core->arena.size;
	return (1);
}
