/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 23:52:00 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/05 00:38:00 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_array.h"
#include "libft_str.h"

static t_array	ft_split_string_aux(const char *s, char c, size_t word)
{
	char	**result;
	size_t	l;

	while (*s == c)
		++s;
	if (*s == '\0')
		return (ft_array_create(sizeof(*result) * word));
	l = 1;
	while (s[l] != c && s[l] != '\0')
		++l;
	result = (char **)ft_split_string_aux(s + l, c, word + 1);
	if (result == NULL)
		return (NULL);
	result[word] = (char *)malloc(sizeof(*result) * (l + 1));
	if (result[word] == NULL)
	{
		l = ft_array_length((t_array)result) / sizeof(*result);
		while (++word < l)
			free(result[word]);
		ft_array_delete((t_array)result);
		return (NULL);
	}
	ft_memcpy(result[word], s, l);
	result[word][l] = '\0';
	return ((t_array)result);
}

t_array			ft_split_string(const char *s, char c)
{
	return (ft_split_string_aux(s, c, 0));
}
