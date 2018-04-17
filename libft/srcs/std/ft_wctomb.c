/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:31:59 by sboilard          #+#    #+#             */
/*   Updated: 2018/01/04 18:26:03 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "libft_std.h"

int	ft_wctomb(char *str, wchar_t c)
{
	size_t	len;
	size_t	i;

	if (c < 0)
		return (-1);
	if (c < 0x80 || (MB_CUR_MAX == 1 && c < 0x100))
	{
		*str = c;
		return (1);
	}
	if (c >= 0x110000 || (c >= 0xD800 && c < 0xE000))
		return (-1);
	len = 2 + (c >= 0x800) + (c >= 0x10000);
	if (len > (size_t)MB_CUR_MAX)
		return (-1);
	str[0] = (char)0xC0 >> (len - 2);
	i = len - 1;
	while (i > 0)
	{
		str[i--] = (c & 0x3F) | 0x80;
		c >>= 6;
	}
	str[0] |= c;
	return (len);
}
