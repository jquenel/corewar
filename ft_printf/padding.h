/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:25:35 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/12 15:29:10 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PADDING_H
# define PADDING_H

# include "buffer.h"
# include "format.h"

void	put_front_padding(unsigned int payload_size, int neg, t_buffer *buffer,
							t_format *format);
void	put_back_padding(unsigned int payload_size, t_buffer *buffer,
						t_format *format);

#endif
