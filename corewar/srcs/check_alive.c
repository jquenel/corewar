/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:13:58 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/13 00:07:23 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_bo	*kill_proc(t_sen *core, t_bo **proc, t_bo *dead)
{
	t_bo		*tmp;

	if (dead == *proc)
	{
		*proc = dead->next;
		if (*proc)
			(*proc)->prev = NULL;
		if (core->opt & OPT_VISU && dead == core->visu->select_proc)
			core->visu->select_proc = dead->next;
		free(dead);
		return (*proc);
	}
	dead->prev->next = dead->next;
	if (dead->next)
		dead->next->prev = dead->prev;
	if (core->opt & OPT_VISU && dead == core->visu->select_proc)
		core->visu->select_proc = dead->next ? dead->next : dead->prev;
	tmp = dead->next;
	free(dead);
	return (tmp);
}

static int	check_alive_proc(t_sen *core, t_bo **proc)
{
	int		count;
	t_bo	*tmp;

	tmp = *proc;
	count = 0;
	while (tmp)
	{
		if (tmp->live < 1)
			tmp = kill_proc(core, proc, tmp);
		else
		{
			count++;
			tmp->live = 0;
			tmp = tmp->next;
		}
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

static int	check_alive(t_sen *core, t_bushi *player, t_bo **proc)
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
	if (!check_alive_proc(core, proc))
		return (0);
	return (count);
}

int			tsumego(t_sen *core)
{
	int		alive;

	if (core->opt & OPT_DETH)
		alive = check_alive(core, core->player, &core->proc);
	else
	{
		set_live_zero(core->player);
		alive = check_alive_proc(core, &(core->proc));
	}
	core->state.c_count -= core->state.c_todie;
	if (core->state.l_count >= core->state.l_limit
			|| ++core->state.l_checks == core->state.l_checks_limit)
	{
		core->state.l_checks = 0;
		if ((core->state.c_todie -= core->state.c_delta) < 0)
			core->state.c_todie = 0;
	}
	if (core->opt & OPT_VISU)
	{
		Mix_PlayChannel(1, core->visu->end_sound, 0);
		Mix_Volume(1, 20);
	}
	core->state.l_count = 0;
	return (alive);
}
