/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:14:46 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/11 16:49:57 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_stpncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	while (n > 0 && *src != '\0')
	{
		*dest++ = *src++;
		--n;
	}
	i = 0;
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
