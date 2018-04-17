/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:46:32 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/11 16:41:47 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"

static int	is_blank(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	l;
	char	*result;

	while (is_blank(*s))
		++s;
	i = 0;
	l = 0;
	while (s[i] != '\0')
		if (!is_blank(s[i++]))
			l = i;
	result = (char *)malloc(sizeof(*result) * (l + 1));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s, l);
	result[l] = '\0';
	return (result);
}
