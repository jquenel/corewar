/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:02:14 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/17 19:58:02 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_fork(t_sen *core, t_bo *actual, t_arg *args)
{
	t_bo	*fork;

	actual->parent->proc_count++;
	if (!(fork = malloc(sizeof(t_bo))))
		malloc_error(core, core->visu);
	ft_memcpy(fork, actual, sizeof(t_bo));
	fork->pc = (fork->pc + dtoi(args[0].data, args[0].size) % IDX_MOD);
	while (fork->pc < 0)
		fork->pc = core->arena.size + fork->pc;
	fork->pc %= core->arena.size;
	fork->next = core->proc;
	fork->prev = NULL;
	core->proc->prev = fork;
	core->proc = fork;
	fork->cycle = -1;
	if (core->opt & OPT_VERB)
		ft_printf("[PID :: %p]\t[ fork ]\t:\t(pc(%d) (%+d))\n",
		actual, fork->pc,
		dtoi(args[0].data, args[0].size) % IDX_MOD);
	return (1);
}
