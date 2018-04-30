/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/04/23 17:20:53 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	power256(int p)
{
	int		result;

	if (p == 0)
		return (1);
	result = 1;
	while (p--)
		result *= 256;
	return (result);
}

static int	neg_dtoi(char *data, int size)
{
	int	result;
	int		i;

	result = 0;
	i = 0;
	while (i < size)
	{
		result *= 256;
		result += (unsigned char)(data[i]);
		i++;
	}
	return (-(power256(size) - result));
}

int		dtoi(char *data, int size)
{
	int		result;
	int		i;

	if (data[0] < 0)
		return (neg_dtoi(data, size));
	result = 0;
	i = 0;
	while (i < size)
	{
		result *= 256;
		result += (unsigned char)(data[i]);
		i++;
	}
	return (result);
}
