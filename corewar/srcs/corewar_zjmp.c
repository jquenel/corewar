/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:38:37 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/17 19:58:23 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_zjmp(t_sen *core, t_bo *actual, t_arg *args)
{
	if (actual->carry != 1)
		return (1);
	actual->pc += dtoi(args[0].data, args[0].size) % IDX_MOD;
	while (actual->pc < 0)
		actual->pc = core->arena.size + actual->pc;
	actual->pc %= core->arena.size;
	if (core->opt & OPT_VERB)
		ft_printf("[PID :: %p]\t[ zjmp ]\t:\t(pc(%d) (%+d))\n",
		actual, actual->pc,
		dtoi(args[0].data, args[0].size) % IDX_MOD);
	return (0);
}
