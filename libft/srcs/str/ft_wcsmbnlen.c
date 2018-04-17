/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsmbnlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:21:02 by sboilard          #+#    #+#             */
/*   Updated: 2018/01/04 18:24:55 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>

size_t	ft_wcsmbnlen(const wchar_t *s, size_t len)
{
	size_t	i;
	size_t	l;
	wchar_t	c;

	i = 0;
	while (i < len && (c = *s) != '\0')
	{
		if (c < 0)
			return ((size_t)-1);
		if (c < 0x80 || (MB_CUR_MAX == 1 && c < 0x100))
			l = 1;
		else
		{
			if (c >= 0x110000 || (c >= 0xD800 && c < 0xE000))
				return ((size_t)-1);
			l = 2 + (c >= 0x800) + (c >= 0x10000);
			if (l > (size_t)MB_CUR_MAX)
				return ((size_t)-1);
			if (i + l > len)
				return (i);
		}
		i += l;
		++s;
	}
	return (i);
}
