/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:08:16 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/06 14:39:38 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	cycle_all(t_bo *proc, int min)
{
	while (proc)
	{
		proc->cycle -= min;
		proc = proc->next;
	}
}

static int	get_min_cycle(t_bo *proc)
{
	int		min;

	min = INT_MAX;
	while (proc)
	{
		if (proc->cycle < min)
			min = proc->cycle;
		proc = proc->next;
	}
	return (min);
}

int			fast_cycle(t_sen *core, t_optab op[OP_COUNT + 1])
{
	t_bo	*tmp;
	int		min;

	tmp = core->proc;
	while (tmp)
	{
		if (tmp->cycle < 0)
			tmp->cycle += plan_op(core, tmp, op);
		tmp = tmp->next;
	}
	min = get_min_cycle(core->proc);
	ft_printf("%d   %d\n", core->state.c_count, min);
	if (core->state.c_count + min >= core->state.c_todie)
		return (-min);
	cycle_all(core->proc, min);
	tmp = core->proc;
	while (tmp)
	{
		if (tmp->cycle == 0 && tmp->op)
			do_op(core, tmp);
		tmp = tmp->next;
	}
	return (min <= 0 ? 1 : min);
}
