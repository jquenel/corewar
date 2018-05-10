/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:00:50 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/10 17:19:11 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "template.h"

void		malloc_error(t_sen *core, t_visu *visu)
{
	destroy_processes(core->proc);
	if (visu)
		destroy_t_visu(visu);
	//free(core->arena.field);
	//free(core->arena.ptrace);
	ft_putendl_fd("ERROR : Out of memory", 2);
	exit(1);
}
