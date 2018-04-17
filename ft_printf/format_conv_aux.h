/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conv_aux.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 00:53:33 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/10 02:32:57 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_CONV_AUX_H
# define FORMAT_CONV_AUX_H

# include "format.h"

void	read_conv_acdefgi(char conv, t_format *format);
void	read_conv_nopsux(char conv, t_format *format);
void	read_conv_pct_up_acdef(char conv, t_format *format);
void	read_conv_up_gosux(char conv, t_format *format);

#endif
