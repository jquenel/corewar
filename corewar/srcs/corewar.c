/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:29:20 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/25 14:50:28 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>

static void		usage(void)
{
	ft_putendl("Usage : corewar [-dump nbr_cycles] \
			[[-n number] champion1.cor] ...");
	exit(1);
}

static void		destroy_arena(t_ban *arena)
{
	if (arena->field)
		free(arena->field);
	if (arena->trace)
		free(arena->trace);
}

int				main(int argc, char **argv)
{
	t_sen		core;

	if (argc < 2)
		usage();
	if (parser(argc - 1, &(argv[1]), &core))
		usage();
	introduce_champions(&core);
	start_battle(&core);
	destroy_processes(core.proc);
	destroy_arena(&core.arena);
}
