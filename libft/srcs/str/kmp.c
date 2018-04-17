/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:36:57 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/11 17:08:18 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"

long	*kmp_make_partial_match_table(const char *str)
{
	long	*part;
	size_t	i;
	long	j;

	part = (long *)malloc(sizeof(*part) * ft_strlen(str));
	if (part == NULL)
		return (NULL);
	part[0] = -1;
	i = 1;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == str[j])
			part[i] = part[j];
		else
		{
			part[i] = j;
			j = part[j];
			while (j >= 0 && str[i] != str[j])
				j = part[j];
		}
		++i;
		++j;
	}
	return (part);
}
