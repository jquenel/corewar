/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:46:56 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/11 16:34:10 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cycle(t_sen *core, t_optab op[OP_COUNT + 1])
{
	t_bo	*tmp;

	tmp = core->proc;
	while (tmp)
	{
		if (tmp->cycle == 0)
		{
			if (tmp->op)
				do_op(core, tmp);
		}
		if (tmp->cycle < 0)
			tmp->cycle = plan_op(core, tmp, op);
		tmp->cycle--;
		tmp = tmp->next;
	}
	return (1);
}
