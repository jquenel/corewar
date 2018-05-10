/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_regs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:57:45 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/10 19:11:09 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_regs(t_arg *args, int *is_reg, int i)
{
	while (i--)
	{
		if (args[i].type == T_REG)
		{
			if ((unsigned int)(args[i].data[0]
				= (char)(dtoi(args[i].data, args[i].size) - 1)) > 15)
				return (0);
			is_reg[i] = 1;
			args[i].size = REG_SIZE;
		}
		else
			is_reg[i] = 0;
	}
	return (1);
}
