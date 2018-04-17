/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:49:04 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/15 22:21:38 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "buffer.h"
#include "conversions.h"
#include "format.h"
#include "ft_printf.h"

static int	perform_conv(t_buffer *buffer, t_format *format, va_list *args)
{
	if (format->conversion == INTEGER)
		perform_integer_conv(buffer, format, args);
	else if (format->conversion == STRING)
		return (perform_string_conv(buffer, format, args));
	else if (format->conversion == CHAR)
		return (perform_char_conv(buffer, format, args));
	else if (format->conversion == FLOAT)
		perform_float_conv(buffer, format, args);
	else if (format->conversion == STORE)
		perform_store_conv(buffer, format, args);
	else
		perform_percent_conv(buffer, format);
	return (1);
}

static int	print(const char *format, t_buffer *buffer, va_list *args)
{
	t_format	format_data;

	while (*format != '\0')
	{
		if (*format != '%')
			putchar_buffer(buffer, *format++);
		else
		{
			++format;
			read_flags(&format, &format_data);
			read_field_width(&format, &format_data, args);
			read_precision(&format, &format_data, args);
			read_length_modifier(&format, &format_data);
			read_conversion(*format++, &format_data);
			if (!perform_conv(buffer, &format_data, args))
				return (0);
		}
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_buffer	buffer;
	int			ret;

	init_buffer(&buffer, STDOUT_FILENO);
	va_start(args, format);
	ret = print(format, &buffer, &args);
	va_end(args);
	if (!ret)
		return (-1);
	flush_buffer(&buffer);
	return (buffer.written);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	t_buffer	buffer;
	int			ret;

	init_buffer(&buffer, fd);
	va_start(args, format);
	ret = print(format, &buffer, &args);
	va_end(args);
	if (!ret)
		return (-1);
	flush_buffer(&buffer);
	return (buffer.written);
}
