/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 02:33:40 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/15 01:22:58 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_std.h>
#include <stddef.h>
#include <wchar.h>
#include "buffer.h"

void	putchar_buffer(t_buffer *buffer, char c)
{
	buffer->buffer[buffer->offset++] = c;
	if (buffer->offset == BUFF_SIZE)
		flush_buffer(buffer);
}

void	putnchar_buffer(t_buffer *buffer, char c, int count)
{
	while (count > 0)
	{
		buffer->buffer[buffer->offset++] = c;
		if (buffer->offset == BUFF_SIZE)
			flush_buffer(buffer);
		--count;
	}
}

void	putstr_buffer(t_buffer *buffer, const char *str)
{
	while (*str != '\0')
	{
		buffer->buffer[buffer->offset++] = *str++;
		if (buffer->offset == BUFF_SIZE)
			flush_buffer(buffer);
	}
}

void	putnstr_buffer(t_buffer *buffer, const char *str, size_t len)
{
	while (*str != '\0' && len > 0)
	{
		buffer->buffer[buffer->offset++] = *str++;
		if (buffer->offset == BUFF_SIZE)
			flush_buffer(buffer);
		--len;
	}
}

void	putnwstr_buffer(t_buffer *buffer, const wchar_t *wstr, size_t mblen)
{
	size_t	i;
	int		l;
	char	seq[5];

	i = 0;
	while (i < mblen && *wstr != L'\0')
	{
		l = ft_wctomb(seq, *wstr++);
		putnstr_buffer(buffer, seq, l);
		i += l;
	}
}
