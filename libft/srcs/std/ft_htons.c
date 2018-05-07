/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntohl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 00:59:28 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/07 01:14:35 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "internal/byteorder.h"
#include "libft_std.h"

uint16_t	ft_htons(uint16_t hostshort)
{
	t_byteorder	byteorder;
	uint8_t		b;

	byteorder.b_short[0] = hostshort;
	b = byteorder.b_byte[0];
	byteorder.b_byte[0] = byteorder.b_byte[1];
	byteorder.b_byte[1] = b;
	return (byteorder.b_short[0]);
}
