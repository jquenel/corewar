/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:50:51 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/20 21:56:42 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


#include <stdio.h>

void		dump_core(t_sen *core)
{
	int		i;

	i = 0;
	printf("{%s}{%s}[%d]\n", core->player[0].name, core->player[0].comment, core->player[0].pnum);
	while (i < MEM_SIZE)
	{
		printf("%.2hhx", core->arena.field[i]);
		i++;
		if (i % 32)
			printf(" ");
		else
			printf("\n");
	}
	printf("\n");
	exit (0);
}
