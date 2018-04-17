/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:15:18 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/09 13:06:23 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n != 0)
	{
		--n;
		((char *)dest)[n] = ((char *)src)[n];
	}
	return (dest);
}
