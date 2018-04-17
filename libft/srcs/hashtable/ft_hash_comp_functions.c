/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_comp_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:28:50 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/28 13:02:45 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_str.h"

size_t	ft_hashfun_int(const void *data)
{
	unsigned int	hash;

	hash = *(const unsigned int *)data;
	hash = ((hash >> 16) ^ hash) * 0x45d9f3b;
	hash = ((hash >> 16) ^ hash) * 0x45d9f3b;
	hash = (hash >> 16) ^ hash;
	return (hash);
}

int		ft_compfun_int(const void *i1, const void *i2)
{
	return (*(const int *)i1 - *(const int *)i2);
}

size_t	ft_hashfun_string(const void *data)
{
	size_t				hash;
	const unsigned char	*str;

	hash = 0xcbf29ce484222325;
	str = *(const unsigned char **)data;
	while (*str != '\0')
		hash = hash * 0x100000001b3 ^ *str++;
	return (hash);
}

int		ft_compfun_string(const void *str1, const void *str2)
{
	return (ft_strcmp(*(const char **)str1, *(const char **)str2));
}
