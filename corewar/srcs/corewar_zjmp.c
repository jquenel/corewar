/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:38:37 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/09 22:36:02 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_zjmp(t_sen *core, t_bo *actual, t_arg *args)
{
	if (actual->carry != 1)
	{
		if (core->opt & OPT_VERB)
			ft_printf("A processus failed to zjmp.\n");
		return (1);
	}
	actual->pc += dtoi(args[0].data, args[0].size) % IDX_MOD;
	while (actual->pc < 0)
		actual->pc = core->arena.size + actual->pc;
	actual->pc %= core->arena.size;
	if (core->opt & OPT_VERB)
		ft_printf("[%d][%d] zjmp : %d(%+d).\n", actual->parent->pnum,
		actual->proc_num, actual->pc, dtoi(args[0].data, args[0].size));
	return (0);
}
