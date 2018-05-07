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

static char	*ft_strnew(size_t size)
{
	char		*dest;
	size_t		i;

	if (!(dest = (char *)malloc(sizeof(char) * size + 1)))
		error_exit("Can't execute a ft_strnew", 1);
	i = 0;
	while (i < size + 1)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

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

void		ft_stradd_back(char **s1, char *s2)
{
	char	*tmp;
	size_t	new_size;

	tmp = ft_strdup(*s1);
	free(*s1);
	new_size = 0;
	if (s2)
		new_size += ft_strlen(s2);
	if (tmp)
		new_size += ft_strlen(tmp);
	if (!(*s1 = ft_strnew(new_size)))
		return ;
	ft_strcpy(*s1, tmp);
	ft_strcat(*s1, s2);
	free(tmp);
}
