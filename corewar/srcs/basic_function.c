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

#include "template.h"

int		get_root(int size)
{
	int		i;

	i = 1;
	while ((i + 1) * (i + 1) <= size)
		i++;
	return (i);
}

static int		ft_intlen_base(uintmax_t nbr, unsigned int base_size)
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

char			*ft_itoa_base(int nbr, char *base)
{
	int			len;
	int			base_size;
	int			i;
	char		*dest;

	if (nbr == 0)
		return (ft_strdup("0"));
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

void		ft_stradd_front(char *s1, char **s2)
{
	char	*tmp;
	size_t	new_size;

	tmp = ft_strdup(*s2);
	free(*s2);
	new_size = 0;
	if (s1)
		new_size += ft_strlen(s1);
	if (tmp)
		new_size += ft_strlen(tmp);
	if (!(*s2 = ft_strnew(new_size)))
		return ;
	ft_strcpy(*s2, s1);
	ft_strcat(*s2, tmp);
	free(tmp);
}
