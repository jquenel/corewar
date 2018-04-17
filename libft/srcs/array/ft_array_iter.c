/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 00:42:00 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/05 00:50:00 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_array.h"

void	ft_array_iter(t_array array, size_t item_size, void (*iterf)(void *))
{
	size_t	length;
	size_t	offset;

	length = ((size_t *)array)[-1];
	offset = 0;
	while (offset < length)
	{
		(*iterf)((char *)array + offset);
		offset += item_size;
	}
}
