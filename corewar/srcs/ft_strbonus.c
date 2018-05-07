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

char		*ft_strnew(size_t size)
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
