/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_str_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:10:58 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/18 18:11:38 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_std.h>
#include <libft_str.h>
#include <stdarg.h>
#include <wchar.h>
#include "buffer.h"
#include "conversions.h"
#include "format.h"
#include "padding.h"

int	perform_char_conv(t_buffer *buffer, t_format *format, va_list *args)
{
	int		len;
	int		i;
	char	seq[5];

	if (format->length_modifier == NORMAL)
	{
		put_front_padding(1, 0, buffer, format);
		putchar_buffer(buffer, va_arg(*args, int));
		put_back_padding(1, buffer, format);
	}
	else
	{
		len = ft_wctomb(seq, va_arg(*args, wint_t));
		if (len < 0)
			return (0);
		put_front_padding(len, 0, buffer, format);
		i = 0;
		while (i < len)
			putchar_buffer(buffer, seq[i++]);
		put_back_padding(len, buffer, format);
	}
	return (1);
}

int	perform_string_conv(t_buffer *buffer, t_format *format, va_list *args)
{
	size_t	len;
	char	*str;
	wchar_t	*wstr;

	str = va_arg(*args, char *);
	if (format->length_modifier == NORMAL)
	{
		str = str != NULL ? str : "(null)";
		len = ft_strnlen(str, format->precision);
		put_front_padding(len, 0, buffer, format);
		putnstr_buffer(buffer, str, len);
		put_back_padding(len, buffer, format);
	}
	else
	{
		wstr = str != NULL ? (wchar_t *)str : L"(null)";
		len = ft_wcsmbnlen(wstr, format->precision);
		if (len == (size_t)-1)
			return (0);
		put_front_padding(len, 0, buffer, format);
		putnwstr_buffer(buffer, wstr, len);
		put_back_padding(len, buffer, format);
	}
	return (1);
}
