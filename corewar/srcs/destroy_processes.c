/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_processes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:03:40 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/09 20:13:38 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		destroy_processes(t_sen *core)
{
	t_bo	*tmp;
	t_bo	*tfree;
	int		i;

	i = 0;
	while (i < MAX_OP_CYCLE)
	{
		tmp = core->schedule[i];
		while (tmp)
		{
			tfree = tmp;
			tmp = tmp->next;
			free(tfree);
		}
		i++;
	}
	return (-1);
}
