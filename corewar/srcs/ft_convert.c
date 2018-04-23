/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/04/23 15:21:08 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int ft_convert(t_sen *core, int pos, int size)
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	while (i < size)
	{
		result *= 256;
		result += core->arena.field[(pos + size) % MEM_SIZE];
		i++;
	}
	return (result);
}
