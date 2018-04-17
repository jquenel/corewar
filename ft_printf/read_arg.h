/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:34:05 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/12 17:53:38 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_ARG_H
# define READ_ARG_H

# include <inttypes.h>
# include <stdarg.h>

uintmax_t	read_signed_int_arg(t_format *format, va_list *args);
uintmax_t	read_unsigned_int_arg(t_format *format, va_list *args);

#endif
