/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itobuf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:49:56 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/07 15:46:23 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

static int		ft_intlen(intmax_t nbr)
{
	int		size;

	if (nbr == 0)
		return (1);
	size = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size++);
}

char			*ft_itobuf(int n, char buffer[12])
{
	int		i;
	int		sign;
	int		pow;
	int		len;
	int		tmp;

	i = 0;
	pow = ft_intlen(n);
	len = n >= 0 ? pow : pow + 1;
	buffer[len] = '\0';
	sign = n < 0 ? -1 : 1;
	if (n < 0)
		buffer[i++] = '-';
	while (i < len)
	{
		buffer[i] = (n / pow) * sign;
		n -= n / pow;
		pow /= 10;
		i++;
	}
	return (buffer);
}
