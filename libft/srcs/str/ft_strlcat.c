/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:16:01 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/09 20:18:02 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

size_t	ft_strlcat(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	l;

	l = 0;
	while (l < n && dest[l] != '\0')
		++l;
	i = 0;
	while (l + i + 1 < n && src[i] != '\0')
	{
		dest[l + i] = src[i];
		++i;
	}
	if (l + i < n)
		dest[l + i] = '\0';
	while (src[i] != '\0')
		++i;
	return (l + i);
}
