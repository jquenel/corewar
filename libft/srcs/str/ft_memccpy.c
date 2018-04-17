/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:15:02 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/10 15:08:11 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	uc_c;
	unsigned char	*uc_dest;
	unsigned char	*uc_src;

	uc_c = (unsigned char)c;
	uc_dest = (unsigned char*)dest;
	uc_src = (unsigned char*)src;
	while (n > 0)
	{
		*uc_dest = *uc_src;
		if (*uc_src == uc_c)
			return ((void *)(uc_dest + 1));
		++uc_src;
		++uc_dest;
		--n;
	}
	return (NULL);
}
