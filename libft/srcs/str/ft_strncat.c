/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:16:10 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/07 20:16:13 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_strncat(char *dest, char *src, size_t n)
{
	char	*start;

	start = dest;
	while (*dest != '\0')
		++dest;
	while (*src != '\0' && n > 0)
	{
		*dest++ = *src++;
		--n;
	}
	*dest = '\0';
	return (start);
}
