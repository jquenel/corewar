/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:00:50 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/11 16:43:31 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "template.h"

void		malloc_error(t_sen *core, t_visu *visu)
{
	destroy_processes(core->proc);
	if (visu)
		destroy_t_visu(visu);
	if (core->arena.field)
		free(core->arena.field);
	if (core->arena.trace)
		free(core->arena.trace);
	ft_putendl_fd("ERROR : Out of memory", 2);
	exit(1);
}
