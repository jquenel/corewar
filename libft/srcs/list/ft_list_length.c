/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:40:39 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 04:57:56 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_list.h"

size_t	ft_list_length(const t_list *list)
{
	size_t	c;

	c = 0;
	while (list != NULL)
	{
		list = list->next;
		++c;
	}
	return (c);
}
