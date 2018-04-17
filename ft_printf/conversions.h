/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:05:30 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/15 22:18:40 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

# include <stdarg.h>
# include "buffer.h"
# include "format.h"

void	perform_integer_conv(t_buffer *buffer, t_format *format, va_list *args);
int		perform_char_conv(t_buffer *buffer, t_format *format, va_list *args);
int		perform_string_conv(t_buffer *buffer, t_format *format, va_list *args);
void	perform_float_conv(t_buffer *buffer, t_format *format, va_list *args);
void	perform_store_conv(t_buffer *buffer, t_format *format, va_list *args);
void	perform_percent_conv(t_buffer *buffer, t_format *format);

#endif
