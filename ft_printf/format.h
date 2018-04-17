/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:52:45 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/12 17:45:37 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include <limits.h>
# include <stdarg.h>

typedef enum	e_flags
{
	ALT_FORM = 1,
	PAD_ZEROES = 1 << 1,
	ALIGN_LEFT = 1 << 2,
	PUT_SPACE = 1 << 3,
	PUT_SIGN = 1 << 4,
	PUT_SEP = 1 << 5,
	UPPERCASE = 1 << 16,
	SIGNED = 1 << 17,
	SCI_FORMAT = 1 << 18,
	SHORTEST = 1 << 19,
	PTR_FORM = 1 << 20
}				t_flag;

typedef enum	e_length_mod
{
	NORMAL,
	HALF,
	HALF_HALF,
	LONG,
	LONG_LONG,
	MAX_TYPE,
	SIZE_TYPE,
	PTRDIFF_TYPE,
	LONG_DOUBLE
}				t_length_mod;

typedef enum	e_conversion
{
	INTEGER,
	STRING,
	CHAR,
	FLOAT,
	STORE,
	PERCENT
}				t_conversion;

typedef struct	s_format
{
	int				flags;
	unsigned int	field_width;
	unsigned int	precision;
	t_length_mod	length_modifier;
	t_conversion	conversion;
	unsigned int	base;
}				t_format;

# define PREC_OMITED UINT_MAX

void			read_flags(const char **format_str, t_format *format);
void			read_field_width(const char **format_str, t_format *format,
								va_list *args);
void			read_precision(const char **format_str, t_format *format,
								va_list *args);
void			read_length_modifier(const char **format_str, t_format *format);
void			read_conversion(char conv, t_format *format);

#endif
