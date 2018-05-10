/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:08:16 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/10 22:15:05 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_vic(t_sen *core, t_bo *actual, t_arg *args)
{
	int			reg;

	(void)core;
	reg = dtoi(args[0].data, args[0].size) - 1;
	if ((unsigned int)reg > 15)
		return (1);
	actual->parent->vic_shout[actual->parent->vic_ccount % MAX_VIC_LEN] =
				actual->reg[reg][REG_SIZE - 1] % 128;
	return (1);
}
