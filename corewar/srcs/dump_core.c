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

void		dump_core(t_sen *core)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%x", core->arena.field[i]);
		if (i % 64)
			ft_printf(" ");
		else
			ft_printf("\n");
	}
	ft_printf("\n");
}