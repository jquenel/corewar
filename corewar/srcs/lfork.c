/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:51:05 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:32:10 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_lfork(t_sen *core, t_bo *actual, t_arg *args)
{
	t_bo	*tmp;

	tmp = actual->next;
	if (!(actual->next = malloc(sizeof(t_bo))))
		malloc_error(core);
	ft_memcpy(actual->next, actual, sizeof(t_bo));
	actual->next->next = tmp;
	actual->next->pc = (actual->next->pc +
				ft_convert(core, args[0].data - FIELD, args[0].size))
				% core->arena.size;
	return (1);
}
