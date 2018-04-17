/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:23:06 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/15 01:52:56 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "format.h"
#include "padding.h"

void	put_front_padding(unsigned int payload_size, int neg, t_buffer *buffer,
							t_format *format)
{
	if (!(format->flags & ALIGN_LEFT)
		&& (!(format->flags & PAD_ZEROES)
			|| (format->precision != PREC_OMITED
				&& format->conversion == INTEGER)))
		putnchar_buffer(buffer, ' ', format->field_width - payload_size);
	if (format->flags & SIGNED)
	{
		if (neg)
			putchar_buffer(buffer, '-');
		else if (format->flags & PUT_SIGN)
			putchar_buffer(buffer, '+');
		else if (format->flags & PUT_SPACE)
			putchar_buffer(buffer, ' ');
	}
	else if ((format->flags & ALT_FORM) && format->base == 16)
		putstr_buffer(buffer, format->flags & UPPERCASE ? "0X" : "0x");
	if (!(format->flags & ALIGN_LEFT) && (format->flags & PAD_ZEROES)
		&& (format->precision == PREC_OMITED || format->conversion != INTEGER))
		putnchar_buffer(buffer, '0', format->field_width - payload_size);
}

void	put_back_padding(unsigned int payload_size, t_buffer *buffer,
						t_format *format)
{
	if (format->flags & ALIGN_LEFT)
		putnchar_buffer(buffer, ' ', format->field_width - payload_size);
}
