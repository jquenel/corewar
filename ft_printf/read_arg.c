/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:34:09 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/12 17:53:52 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdarg.h>
#include <stddef.h>
#include "format.h"
#include "read_arg.h"

uintmax_t	read_signed_int_arg(t_format *format, va_list *args)
{
	int	l;

	l = format->length_modifier;
	if (l == NORMAL)
		return (va_arg(*args, int));
	if (l == HALF)
		return ((short)va_arg(*args, int));
	if (l == HALF_HALF)
		return ((char)va_arg(*args, int));
	if (l == LONG)
		return (va_arg(*args, long));
	if (l == LONG_LONG)
		return (va_arg(*args, long long));
	if (l == MAX_TYPE)
		return (va_arg(*args, intmax_t));
	if (l == SIZE_TYPE)
		return (va_arg(*args, size_t));
	return (va_arg(*args, ptrdiff_t));
}

uintmax_t	read_unsigned_int_arg(t_format *format, va_list *args)
{
	int	l;

	l = format->length_modifier;
	if (l == NORMAL)
		return (va_arg(*args, unsigned int));
	if (l == HALF)
		return ((unsigned short)va_arg(*args, unsigned int));
	if (l == HALF_HALF)
		return ((unsigned char)va_arg(*args, unsigned int));
	if (l == LONG)
		return (va_arg(*args, unsigned long));
	if (l == LONG_LONG)
		return (va_arg(*args, unsigned long long));
	if (l == MAX_TYPE)
		return (va_arg(*args, uintmax_t));
	if (l == SIZE_TYPE)
		return (va_arg(*args, size_t));
	return (va_arg(*args, ptrdiff_t));
}
