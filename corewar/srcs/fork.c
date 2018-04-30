/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:02:14 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:31:16 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_fork(t_sen *core, t_bo *actual, t_arg *args)
{
	t_bo	*tmp;

	tmp = actual->next;
	if (!(actual->next = malloc(sizeof(t_bo))))
		malloc_error(core);
	ft_memcpy(actual->next, actual, sizeof(t_bo));
	actual->next->next = tmp;
	actual->next->pc = (actual->next->pc +
				dtoi(args[0].data, args[0].size) % IDX_MOD);
	while (actual->next->pc < 0)
		actual->next->pc = core->arena.size + actual->next->pc;
	actual->next->pc %= core->arena.size;
	actual->next->cycle = -1;
	return (1);
}
