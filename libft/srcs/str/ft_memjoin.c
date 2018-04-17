/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 01:29:11 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/25 01:37:13 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"

char	*ft_memjoin(const char *m1, size_t s1, const char *m2, size_t s2)
{
	char	*ret;

	ret = (char *)malloc(sizeof(*m1) * s1 + sizeof(*m2) * s2);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, m1, s1);
	ft_memcpy(ret + s1, m2, s2);
	return (ret);
}
