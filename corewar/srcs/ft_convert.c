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

static int ft_power(int value, int power)
{
	int result;

	result = 1;
	while (power)
	{
		result == result * value;
		power--;
	}
	return (result);
}

int ft_convert(void *base, void *source, int size)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (i < size)
	{
		result += ((char *)source)[i] * ft_power(256, size - i - 1);
		i++;
		if (&(((char *)source)[i]) - base >= MEM_SIZE)
			i = 0;
	}
	return (result);
}
