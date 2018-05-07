/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:13:58 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/06 19:04:20 by jquenel          ###   ########.fr       */
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

static void	set_live_zero(t_bushi *player)
{
	int		i;

	i = MAX_PLAYERS;
	while (i--)
		player[i].live = player[i].live == -2 ? -2 : 0;
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

int			tsumego(t_sen *core)
{
	int		alive;

	if (core->opt & OPT_DETH)
		alive = check_alive(core->player, &core->proc);
	else
	{
		set_live_zero(core->player);
		alive = check_alive_proc(&(core->proc));
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
