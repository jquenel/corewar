/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:17:18 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/10 15:21:11 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(*result) * (len + 1));
	if (result == NULL)
		return (NULL);
	s += start;
	i = 0;
	while (i < len)
	{
		result[i] = s[i];
		++i;
	}
	result[len] = '\0';
	return (result);
}
