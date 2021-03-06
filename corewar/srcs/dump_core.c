/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:50:51 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/21 22:09:36 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		dump_core(t_sen *core)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (!(i % 64))
		{
			if (i)
				ft_printf("%#.4x : ", i);
			else
				ft_printf("0x0000 : ");
		}
		ft_printf("%.2hhx", core->arena.field[i]);
		i++;
		if (i % 64)
			ft_printf(" ");
		else
			ft_printf("\n");
	}
	destroy_processes(core->proc);
	exit(0);
}
