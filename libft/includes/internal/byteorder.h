/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byteorder.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 01:03:34 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/07 01:22:58 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BYTEORDER_H
# define BYTEORDER_H

# include <stdint.h>

typedef union	u_byteorder
{
	uint32_t	b_int;
	uint16_t	b_short[2];
	uint8_t		b_byte[4];
}				t_byteorder;

#endif
