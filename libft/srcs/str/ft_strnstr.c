/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:41:23 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/11 17:08:02 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/kmp.h"

static char	*search(const char *s1, const char *s2, size_t len,
					const long *part)
{
	size_t	i;
	long	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == s2[j])
		{
			if (s2[++j] == '\0')
				return ((char *)s1 + i + 1 - j);
		}
		else
		{
			j = part[j];
			while (j >= 0 && s1[i] != s2[j])
				j = part[j];
			++j;
		}
		++i;
	}
	return (NULL);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	long	*part;
	char	*result;

	if (*s2 == '\0')
		return ((char *)s1);
	part = kmp_make_partial_match_table(s2);
	if (part == NULL)
		return (NULL);
	result = search(s1, s2, len, part);
	free(part);
	return (result);
}
