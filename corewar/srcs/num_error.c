/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 21:20:30 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/21 21:30:15 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "template.h"

void		num_error(t_sen *core)
{
	destroy_processes(core->proc);
	if (core->arena.field)
		free(core->arena.field);
	if (core->arena.trace)
		free(core->arena.trace);
	ft_putendl_fd("ERROR : Bad player number", 2);
	exit(1);
}

