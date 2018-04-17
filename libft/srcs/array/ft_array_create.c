/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:33:00 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/13 20:20:07 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_array.h"

t_array	ft_array_create(size_t size)
{
	void	*array;

	if ((array = malloc(size + sizeof(void *))) == NULL)
		return (NULL);
	array += sizeof(void *);
	((size_t *)array)[-1] = size;
	return (array);
}
