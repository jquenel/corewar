/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:29:20 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/25 23:16:21 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>

static void		usage(void)
{
	ft_printf(
			"Usage : corewar [-dump nbr_cycles]"
			"[-aisvw][[-n number] champion1.cor] ...\n"
			"--------------------------------------------------"
			"--------------------------------------------------\n"
			"-dump n		Stops the program after n cycles are executes,"
			" and prints the state of the memory.\n"
			"-a		Activates the aff option (default off).\n"
			"-i		Use extra instructions (mul, div, not, vic).\n"
			"-s		Sudden death mode ! Permanent death awaits players who"
			"do not execute live during a cycle.\n"
			"-v		Visual mode, e-sport ready.\n"
			"-w		Verbose.\n"
			"--------------------------------------------------"
			"--------------------------------------------------\n"
			);
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
