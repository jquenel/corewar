/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2017/11/25 00:41:35 by jboissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void corewar_ld(t_sen *arena, t_bo *actual, t_arg *arg_list)
{
	int		value_size;
	void	*dest;

	if (arg_list[0] == NULL || arg_list[1] == NULL ||
		(arg_list[0]->type != 2 && arg_list[0]->type != 3) ||
		arg_list[1]->type != 1)
	{
		if (actual != NULL)
			actual->carry = 0;
		return ;
	}
	value_size = (arg_list[0]->type == 1 ? REG_SIZE : DIR_SIZE);
	if (arg_list[1]->type == 3)
		dest = ft_calc_pc(arena->arena, actual, ft_convert(arg_list[1]->data,
															arg_list[1]->size));
	else
		dest = ((int *)actual->reg) + ft_convert(arg_list[1]->data,
										arg_list[1]->size);
	ft_memcpy (dest, value_size, value_size);
	if (actual != NULL)
		actual->carry = 1;
}
