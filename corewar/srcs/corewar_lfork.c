/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:51:05 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/13 00:08:01 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_lfork(t_sen *core, t_bo *actual, t_arg *args)
{
	t_bo	*fork;

	actual->parent->proc_count++;
	if (!(fork = malloc(sizeof(t_bo))))
		malloc_error(core, core->visu);
	ft_memcpy(fork, actual, sizeof(t_bo));
	fork->pc = (fork->pc + dtoi(args[0].data, args[0].size)) % MEM_SIZE;
	while (fork->pc < 0)
		fork->pc = core->arena.size + fork->pc;
	fork->pc %= core->arena.size;
	fork->next = core->proc;
	core->proc->prev = fork;
	core->proc = fork;
	fork->cycle = -1;
	return (1);
}
