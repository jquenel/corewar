/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:59:40 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/15 02:12:19 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>
#include <stdarg.h>
#include "format.h"
#include "format_conv_aux.h"

void	read_flags(const char **format_str, t_format *format)
{
	const char		flags[] = { '#', '0', '-', ' ', '+', '\'' };
	int				f;
	unsigned int	i;
	char			c;

	f = 0;
	i = 0;
	c = **format_str;
	while (i < sizeof(flags) / sizeof(*flags))
	{
		if (c != flags[i])
			++i;
		else
		{
			f |= 1 << i;
			i = 0;
			c = *++*format_str;
		}
	}
	format->flags = f;
}

void	read_field_width(const char **format_str, t_format *format,
						va_list *args)
{
	int	w;

	if (**format_str == '*')
	{
		++*format_str;
		w = va_arg(*args, int);
		if (w < 0)
		{
			w = -w;
			format->flags |= ALIGN_LEFT;
		}
	}
	else
	{
		w = 0;
		while (ft_isdigit(**format_str))
			w = w * 10 + *(*format_str)++ - '0';
	}
	format->field_width = w;
}

void	read_precision(const char **format_str, t_format *format, va_list *args)
{
	int	p;

	if (**format_str != '.')
	{
		format->precision = PREC_OMITED;
		return ;
	}
	if (*++*format_str == '*')
	{
		++*format_str;
		p = va_arg(*args, int);
		if (p < 0)
			p = PREC_OMITED;
	}
	else
	{
		p = 0;
		while (ft_isdigit(**format_str))
			p = p * 10 + *(*format_str)++ - '0';
	}
	format->precision = p;
}

void	read_length_modifier(const char **format_str, t_format *format)
{
	char	c;

	c = *(*format_str)++;
	if (c == 'h' || c == 'l')
	{
		format->length_modifier = c == 'h' ? HALF : LONG;
		if (c == **format_str)
		{
			++format->length_modifier;
			++*format_str;
		}
	}
	else if (c == 'j')
		format->length_modifier = MAX_TYPE;
	else if (c == 'z')
		format->length_modifier = SIZE_TYPE;
	else if (c == 't')
		format->length_modifier = PTRDIFF_TYPE;
	else if (c == 'L')
		format->length_modifier = LONG_DOUBLE;
	else
	{
		--*format_str;
		format->length_modifier = NORMAL;
	}
}

void	read_conversion(char conv, t_format *format)
{
	format->base = 10;
	if (conv > 'Z')
	{
		if (conv < 'n')
			read_conv_acdefgi(conv, format);
		else
			read_conv_nopsux(conv, format);
	}
	else if (conv < 'G')
		read_conv_pct_up_acdef(conv, format);
	else
		read_conv_up_gosux(conv, format);
}
