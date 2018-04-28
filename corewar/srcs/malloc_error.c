/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:00:50 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:19:59 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		malloc_error(t_sen *core)
{
	destroy_processes(core->proc);
	//free(core->arena.field);
	//free(core->arena.ptrace);
	ft_putendl_fd("ERROR : Out of memory", 2);
	exit(1);
}