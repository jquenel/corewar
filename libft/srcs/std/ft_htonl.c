/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htonl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 00:59:28 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/07 01:10:03 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "internal/byteorder.h"
#include "libft_std.h"

uint32_t	ft_htonl(uint32_t hostlong)
{
	t_byteorder	byteorder;
	uint8_t		b;

	byteorder.b_int = hostlong;
	b = byteorder.b_byte[0];
	byteorder.b_byte[0] = byteorder.b_byte[3];
	byteorder.b_byte[3] = b;
	b = byteorder.b_byte[1];
	byteorder.b_byte[1] = byteorder.b_byte[2];
	byteorder.b_byte[2] = b;
	return (byteorder.b_int);
}
