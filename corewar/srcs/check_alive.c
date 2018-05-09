/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:13:58 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/09 23:57:21 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_bo	*kill_proc(t_bo **proc, t_bo *dead, t_bo *prev)
{
	t_bo		*tmp;

	dead->parent->proc_count--;
	if (dead->prev)
		dead->prev->next = dead->next;
	if (dead->next)
		dead->next->prev = dead->prev;
	tmp = dead->next;
	if (dead == *proc)
		*proc = dead->next;
	else
		prev->next = dead->next;
	free(dead);
	return (tmp);
}

static int	check_alive_proc(t_sen *core)
{
	t_bo		*tmp1;
	t_bo		*tmp2;
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (i < MAX_OP_CYCLE)
	{
		tmp1 = core->schedule[i];
		tmp2 = NULL;
		while (tmp1)
		{
			if (tmp1->live == 0)
				tmp1 = kill_proc(&core->schedule[i], tmp1, tmp2);
			else
			{
				tmp2 = tmp1;
				tmp1->live = 0;
				tmp1 = tmp1->next;
				count++;
			}
		}
		i++;
	}
	return (count);
}

static void	set_live_zero(t_bushi *player)
{
	int		i;

	i = MAX_PLAYERS;
	while (i--)
		player[i].live = player[i].live == -2 ? -2 : 0;
}

static int	check_alive(t_bushi *player, t_sen *core)
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
	if (!check_alive_proc(core))
		return (0);
	return (count);
}

int			tsumego(t_sen *core)
{
	int		alive;

	if (core->opt & OPT_DETH)
		alive = check_alive(core->player, core);
	else
	{
		set_live_zero(core->player);
		alive = check_alive_proc(core);
	}
	core->state.c_count -= core->state.c_todie;
	if (core->state.l_count >= core->state.l_limit
			|| ++core->state.l_checks == core->state.l_checks_limit)
	{
		core->state.l_checks = 0;
		if ((core->state.c_todie -= core->state.c_delta) < 0)
			core->state.c_todie = 0;
	}
	core->state.l_count = 0;
	return (alive);
}
