/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_iter_ptr_item.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 00:58:00 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/05 01:03:00 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_array.h"

void	ft_array_iter_ptr_item(t_array array, void (*iterf)(void *))
{
	size_t	length;
	size_t	i;

	length = ((size_t *)array)[-1] / 8;
	i = 0;
	while (i < length)
		(*iterf)(((void **)array)[i++]);
}
