/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/04 19:13:33 by jboissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"
#include "corewar.h"

static int		ft_intlen(intmax_t nbr)
{
	int		size;

	if (nbr == 0)
		return (1);
	size = 0;
	if (nbr < 0)
	{
		size++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size++);
}

char			*poor_itoa(int nbr, char *buffer)
{
	int		i;
	int		negative;
	int		len;

	i = 0;
	len = ft_intlen(nbr);
	buffer[len] = '\0';
	len--;
	negative = 0;
	if (nbr < 0)
	{
		buffer[0] = '-';
		negative = 1;
	}
	while (len >= negative)
	{
		buffer[len] = ((nbr % 10) >= 0 ? (nbr % 10) : (nbr % 10) * -1) + '0';
		len--;
		nbr /= 10;
	}
	return (buffer);
}
