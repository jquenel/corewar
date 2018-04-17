/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:15:41 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/09 14:30:14 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_strchr(const char *s, char c)
{
	size_t	i;

	if (*s == c)
		return ((char *)s);
	i = 0;
	while (s[i] != '\0')
		if (s[++i] == c)
			return ((char *)s + i);
	return (NULL);
}
