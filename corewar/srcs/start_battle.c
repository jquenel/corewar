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

static t_bo	*kill_proc(t_bo **proc, t_bo *dead, t_bo *prev)
{
	t_bo		*tmp;

	tmp = dead->next;
	if (dead == *proc)
		*proc = dead->next;
	else
		prev->next = dead->next;
	free(dead);
	return (tmp);
}

static int	check_alive_proc(t_bo **proc)
{
	t_bo		*tmp1;
	t_bo		*tmp2;
	int			count;

	tmp1 = *proc;
	tmp2 = NULL;
	while (tmp1)
	{
		if (tmp1->live == 0)
			tmp1 = kill_proc(proc, tmp1, tmp2);
		else
		{
			tmp2 = tmp1;
			tmp1->live = 0;
			tmp1 = tmp1->next;
		}
	}
	tmp1 = *proc;
	count = 0;
	while (tmp1)
	{
		count++;
		tmp1 = tmp1->next;
	}
	return (count);
}

static int	check_alive(t_bushi *player, t_bo **proc)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (player[i].live != -2)
	{
		if (player[i].live > 0)
		{
			player[i].live = 0;
			count++;
		}
		else
			player[i].live = -1;
		i++;
	}
	if (!check_alive_proc(proc))
		return (0);
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
		//if (!core->visu.pause)
		//{
			//if (core->opt & (1 << ('f' - 'a')))
			//	fast_cycle(core);
			//else
			cycle(core, op);
			if (++core->state.c_total == core->state.dump_limit
					&& core->state.dump_limit > 0)
				dump_core(core);
			if (++core->state.c_count == core->state.c_todie)
			{
				alive = check_alive(core->player, &core->proc);
				if (core->state.l_count >= core->state.l_limit
						|| ++core->state.l_checks == core->state.l_checks_limit)
				{
					core->state.l_checks = 0;
					core->state.c_todie = core->state.c_todie -
						core->state.c_delta
						< 0 ? 0 : core->state.c_todie - core->state.c_delta;
				}
				core->state.c_count = 0;
				core->state.l_count = 0;
			}
		//}
	}
}
