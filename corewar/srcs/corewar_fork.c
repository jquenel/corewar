/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:02:14 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/09 22:36:32 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_fork(t_sen *core, t_bo *actual, t_arg *args)
{
	t_bo	*fork;

	actual->parent->proc_count++;
	if (!(fork = malloc(sizeof(t_bo))))
		malloc_error(core);
	ft_memcpy(fork, actual, sizeof(t_bo));
	fork->pc = (fork->pc + dtoi(args[0].data, args[0].size) % IDX_MOD);
	while (fork->pc < 0)
		fork->pc = core->arena.size + fork->pc;
	fork->pc %= core->arena.size;
	fork->proc_num = core->proc_count++;
	fork->prev = NULL;
	fork->next = NULL;
	plan_op(core, fork, core->optab);
	if (core->opt & OPT_VERB)
		ft_printf("[%d][%d] fork : %d(%+d).\n", actual->parent->pnum,
	actual->proc_num, fork->pc, dtoi(args[0].data, args[0].size));
	return (1);
}
