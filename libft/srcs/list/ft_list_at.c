/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:11:47 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 04:58:14 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_list.h"

t_list	**ft_list_at(t_list **list, size_t index)
{
	while (*list != NULL && index > 0)
	{
		list = &(*list)->next;
		--index;
	}
	return (list);
}
