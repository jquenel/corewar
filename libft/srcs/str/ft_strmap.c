/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:05:05 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/10 16:27:25 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(*result) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = (*f)(s[i]);
		++i;
	}
	result[i] = '\0';
	return (result);
}
