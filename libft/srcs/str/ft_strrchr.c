/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:33:51 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/08 09:10:45 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_strrchr(const char *s, char c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + i);
	while (i != 0)
	{
		--i;
		if (s[i] == c)
			return ((char *)s + i);
	}
	return (NULL);
}
