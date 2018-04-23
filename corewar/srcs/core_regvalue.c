/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_regvalue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:13:38 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/23 18:16:20 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		core_regvalue(char *reg)
{
	int		i;
	int		value;

	i = 0;
	value = 0;
	while (i < REG_SIZE)
	{
		value *= 256;
		value += reg[i];
		i++;
	}
	i = (sizeof(int) - REG_SIZE) * 8;
	return ((value << i) >> i);
}
