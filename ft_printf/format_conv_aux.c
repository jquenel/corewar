/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conv_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 00:41:30 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/12 14:36:07 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "format_conv_aux.h"

void	read_conv_acdefgi(char conv, t_format *format)
{
	if (conv == 'c')
		format->conversion = CHAR;
	else if (conv == 'd' || conv == 'i')
	{
		format->conversion = INTEGER;
		format->flags |= SIGNED;
	}
	else
	{
		format->conversion = FLOAT;
		if (conv == 'e')
			format->flags |= SCI_FORMAT;
		else if (conv == 'g')
			format->flags |= SHORTEST;
		else if (conv == 'a')
		{
			format->base = 16;
			format->flags |= SCI_FORMAT;
		}
	}
}

void	read_conv_nopsux(char conv, t_format *format)
{
	if (conv == 'n')
		format->conversion = STORE;
	else if (conv == 's')
		format->conversion = STRING;
	else
	{
		format->conversion = INTEGER;
		if (conv == 'x')
			format->base = 16;
		else if (conv == 'o')
			format->base = 8;
		else if (conv == 'p')
		{
			format->base = 16;
			format->length_modifier = LONG;
			format->flags |= ALT_FORM | PTR_FORM;
		}
	}
}

void	read_conv_pct_up_acdef(char conv, t_format *format)
{
	if (conv == '%')
		format->conversion = PERCENT;
	else if (conv == 'C')
	{
		format->conversion = CHAR;
		format->length_modifier = LONG;
	}
	else if (conv == 'D')
	{
		format->conversion = INTEGER;
		format->flags |= SIGNED;
		format->length_modifier = LONG;
	}
	else
	{
		format->conversion = FLOAT;
		format->flags |= UPPERCASE;
		if (conv == 'A')
		{
			format->base = 16;
			format->flags |= SCI_FORMAT;
		}
		else if (conv == 'E')
			format->flags |= SCI_FORMAT;
	}
}

void	read_conv_up_gosux(char conv, t_format *format)
{
	if (conv == 'G')
	{
		format->conversion = FLOAT;
		format->flags |= UPPERCASE | SHORTEST;
	}
	else if (conv == 'S')
	{
		format->conversion = STRING;
		format->length_modifier = LONG;
	}
	else
	{
		format->conversion = INTEGER;
		if (conv == 'X')
		{
			format->flags |= UPPERCASE;
			format->base = 16;
		}
		else
		{
			format->length_modifier = LONG;
			if (conv == 'O')
				format->base = 8;
		}
	}
}
