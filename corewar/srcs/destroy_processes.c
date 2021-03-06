/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_processes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:03:40 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:03:43 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		destroy_processes(t_bo *proc)
{
	t_bo	*tmp;

	while (proc)
	{
		tmp = proc;
		proc = proc->next;
		free(tmp);
	}
	return (-1);
}
