/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/06 15:33:45 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
//
void		*ft_calc_pc(t_ban *arena, t_bo *actual, int value)
{
	void *pc;

	pc = (ft_convert(actual->reg[0], 4) + value) % MEM_SIZE;
	return ((void *)(&(arena[pc])));
}
//
