/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/07 16:08:49 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

int					get_root(int size)
{
	int		i;

	i = 1;
	while ((i + 1) * (i + 1) <= size)
		i++;
	printf("root --- i = %d\n", i);
	return (i);
}

static int			ft_intlen_base(uintmax_t nbr, unsigned int base_size)
{
	int		size;

	if (nbr == 0)
		return (1);
	size = 0;
	while (nbr >= base_size)
	{
		nbr /= base_size;
		size++;
	}
	return (size);
}

char				*ft_itoa_base(int nbr, char *base)
{
	int			len;
	int			base_size;
	int			i;
	char		*dest;

	base_size = ft_strlen(base);
	len = ft_intlen_base(nbr, base_size);
	dest = ft_strnew(len + 1);
	i = 0;
	while (nbr > 0)
	{
		dest[len - i] = base[nbr % base_size];
		nbr /= base_size;
		i++;
	}
	dest[len + 1] = '\0';
	return (dest);
}

void				error_exit(char *msg, int error)
{
	ft_printf("Error %d : %s\n", error, msg);
	exit(error);
}
