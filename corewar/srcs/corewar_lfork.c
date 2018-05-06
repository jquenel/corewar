/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:51:05 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/06 16:12:26 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_lfork(t_sen *core, t_bo *actual, t_arg *args)
{
	t_bo	*tmp;

	actual->parent->proc_count++;
	tmp = actual->next;
	if (!(actual->next = malloc(sizeof(t_bo))))
		malloc_error(core);
	ft_memcpy(actual->next, actual, sizeof(t_bo));
	actual->next->next = tmp;
	actual->next->pc = (actual->next->pc +
				dtoi(args[0].data, args[0].size));
	while (actual->next->pc < 0)
		actual->next->pc = core->arena.size + actual->next->pc;
	actual->next->pc %= core->arena.size;
	actual->next->cycle = -1;
	return (1);
}
