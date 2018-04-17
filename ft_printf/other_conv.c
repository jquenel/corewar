/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:16:27 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/15 22:17:29 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "buffer.h"
#include "conversions.h"
#include "format.h"
#include "padding.h"

void	perform_store_conv(t_buffer *buffer, t_format *format, va_list *args)
{
	void		*p;
	intmax_t	w;
	int			l;

	p = va_arg(*args, void *);
	if (p == NULL)
		return ;
	w = buffer->written + buffer->offset;
	l = format->length_modifier;
	if (l == NORMAL)
		*(int *)p = w;
	else if (l == HALF)
		*(short *)p = w;
	else if (l == HALF_HALF)
		*(char *)p = w;
	else if (l == LONG)
		*(long *)p = w;
	else if (l == LONG_LONG)
		*(long long *)p = w;
	else if (l == MAX_TYPE)
		*(intmax_t *)p = w;
	else if (l == SIZE_TYPE)
		*(size_t *)p = w;
	else
		*(ptrdiff_t *)p = w;
}

void	perform_percent_conv(t_buffer *buffer, t_format *format)
{
	put_front_padding(1, 0, buffer, format);
	putchar_buffer(buffer, '%');
	put_back_padding(1, buffer, format);
}
