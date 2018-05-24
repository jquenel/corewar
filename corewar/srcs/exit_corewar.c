/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:48:51 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/17 15:15:09 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "template.h"

void				exit_corewar(t_sen *core)
{
	destroy_processes(core->proc);
	if (core->arena.field)
		free(core->arena.field);
	if (core->arena.trace)
		free(core->arena.trace);
	if (core->opt & OPT_VISU)
	{
		destroy_t_visu(core->visu);
		close_renderer();
	}
	exit(0);
}
