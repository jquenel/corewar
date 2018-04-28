/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_battle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:48:51 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:53:49 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	count_alive(t_bushi *player)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (player[i].live != -2)
	{
		if (player[i].live >= 0)
			count++;
		i++;
	}
	return (count);
}

void		start_battle(t_sen *core)
{
	int			alive;
	t_optab		op[OP_COUNT + 1];

	init_optab(op);

	alive = 2;
	while (alive > 1)
	{
		if (!core->visu.pause)
		{
		//if (core->opt & (1 << ('f' - 'a')))
		//	fast_cycle(core);
		//else
//			cycle(core);
		alive = count_alive(core->player);
		(void)core;
		}
	}
}
