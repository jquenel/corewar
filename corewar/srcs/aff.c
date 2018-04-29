/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:53:02 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 22:55:38 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_aff(t_sen *core, t_bo *actual, t_arg *args)
{
	int			reg;

	(void)core;
	reg = dtoi(args[0].data, args[0].size) - 1;
	if ((unsigned int)reg > 15)
		return (0);
	ft_printf("%c", actual->reg[reg][REG_SIZE - 1]);
	return (1);
}
