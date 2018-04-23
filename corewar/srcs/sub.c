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

void		corewar_sub(t_sen *arena, t_bo *actual, t_arg *arg_list)
{
	int		*arg1;
	int		*arg2;
	void	*dest;
	int		result;

	if (arg_list[0]->type != 1 || arg_list[1]->type != 1 ||
		arg_list[2]->type != 1)
	{
		if (actual != NULL)
			actual->carry = 0;
		return ;
	}
	arg1 = actual->reg[ft_convert(arg_list[0]->data, arg_list[0]->size)];
	arg2 = actual->reg[ft_convert(arg_list[1]->data, arg_list[1]->size)];
	dest = (void *)(&(actual->reg[ft_convert(arg_list[2]->data,
														arg_list[2]->size)]));
	result = arg1 - arg2;
	ft_memcpy(dest, (void *)result, arg_list[2]->size);
	if (actual != NULL)
		actual->carry = 1;
}
