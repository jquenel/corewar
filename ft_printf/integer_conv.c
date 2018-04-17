/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:01:36 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/18 16:41:54 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdarg.h>
#include "aux.h"
#include "buffer.h"
#include "conversions.h"
#include "format.h"
#include "padding.h"
#include "read_arg.h"

static void			put_dec_number_sep(uintmax_t nbr, unsigned int digits,
										t_buffer *buffer)
{
	unsigned int	sep;
	char			str[32];
	char			*it;

	sep = 0;
	str[31] = '\0';
	it = str + 31;
	while (nbr != 0)
	{
		if (sep == 3)
		{
			*--it = ',';
			sep = 1;
		}
		else
			++sep;
		*--it = '0' + nbr % 10;
		nbr /= 10;
	}
	putnchar_buffer(buffer, '0', (int)digits - 31 + (it - str));
	putstr_buffer(buffer, it);
}

static void			put_number(uintmax_t nbr, unsigned int digits,
								t_buffer *buffer, const t_format *format)
{
	int		upcase;
	int		base;
	char	str[24];
	char	*it;

	base = format->base;
	if (!(format->flags & PUT_SEP) || base != 10)
	{
		upcase = (format->flags & UPPERCASE);
		str[23] = '\0';
		it = str + 23;
		while (nbr != 0)
		{
			*--it = char_of_digit(nbr % base, upcase);
			nbr /= base;
		}
		putnchar_buffer(buffer, '0', (int)digits - 23 + (it - str));
		putstr_buffer(buffer, it);
	}
	else
		put_dec_number_sep(nbr, digits, buffer);
}

static unsigned int	count_digits(uintmax_t value, const t_format *format)
{
	unsigned int	base;
	unsigned int	precision;
	int				flags;
	unsigned int	digits;

	base = format->base;
	precision = format->precision;
	flags = format->flags;
	digits = 0;
	while (value != 0)
	{
		++digits;
		value /= base;
	}
	if ((base == 8 && (flags & ALT_FORM))
		|| (digits == 0 && precision == PREC_OMITED))
		++digits;
	else if (base == 10 && (flags & PUT_SEP))
		digits += (digits - 1) / 3;
	if (precision != PREC_OMITED && precision > digits)
		return (precision);
	return (digits);
}

static unsigned int	compute_payload_size(uintmax_t nbr, int neg,
										unsigned int digits, t_format *format)
{
	unsigned int	base;
	int				flags;
	unsigned int	ret;

	base = format->base;
	flags = format->flags;
	ret = 0;
	if (base == 10)
	{
		if ((flags & SIGNED) && (neg || (flags & (PUT_SPACE | PUT_SIGN))))
			++ret;
	}
	else if (base == 16 && flags & ALT_FORM)
	{
		if (nbr != 0 || (flags & PTR_FORM))
			ret += 2;
		else
			format->flags &= ~ALT_FORM;
	}
	return (ret + digits);
}

void				perform_integer_conv(t_buffer *buffer, t_format *format,
										va_list *args)
{
	uintmax_t		nbr;
	int				neg;
	unsigned int	digits;
	unsigned int	payload_size;

	neg = 0;
	if (format->flags & SIGNED)
	{
		nbr = read_signed_int_arg(format, args);
		if ((intmax_t)nbr < 0)
		{
			nbr = -(intmax_t)nbr;
			neg = 1;
		}
	}
	else
		nbr = read_unsigned_int_arg(format, args);
	digits = count_digits(nbr, format);
	payload_size = compute_payload_size(nbr, neg, digits, format);
	put_front_padding(payload_size, neg, buffer, format);
	put_number(nbr, digits, buffer, format);
	put_back_padding(payload_size, buffer, format);
}
