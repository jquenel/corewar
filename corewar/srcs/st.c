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

void corewar_st(t_sen *arena, t_bo *actual, t_arg *arg_list)
{
	int		value_size;
	void	*dest;

	if (arg_list[0] == NULL || arg_list[1] == NULL ||
		(arg_list[1]->type != 1 && arg_list[1]->type != 3) ||
		arg_list[0]->type != 1)
		return ;
	value_size = (arg_list[0]->type == 1 ? REG_SIZE : DIR_SIZE);
	if (arg_list[1]->type == 3)
		dest = ft_calc_pc(arena->arena, actual, ft_convert(arg_list[1]->data,
															arg_list[1]->size));
	else
		dest = ((int *)actual->reg) + ft_convert(arg_list[1]->data,
										arg_list[1]->size);
	ft_memcpy (arg_list[0]->data, dest, value_size);
}
