/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:21:52 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/10 16:33:49 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"

static char	**prepare_tab(size_t words)
{
	char	**result;

	result = (char **)malloc(sizeof(*result) * (words + 1));
	if (result != NULL)
		result[words] = NULL;
	return (result);
}

static char	**ft_strsplit_aux(const char *s, char c, size_t word)
{
	char	**result;
	size_t	l;

	while (*s == c)
		++s;
	if (*s == '\0')
		return (prepare_tab(word));
	l = 1;
	while (s[l] != c && s[l] != '\0')
		++l;
	result = ft_strsplit_aux(s + l, c, word + 1);
	if (result == NULL)
		return (NULL);
	result[word] = (char *)malloc(sizeof(*result) * (l + 1));
	if (result[word] == NULL)
	{
		while (result[++word] != NULL)
			free(result[word]);
		free(result);
		return (NULL);
	}
	ft_memcpy(result[word], s, l);
	result[word][l] = '\0';
	return (result);
}

char		**ft_strsplit(const char *s, char c)
{
	return (ft_strsplit_aux(s, c, 0));
}
