/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:54:23 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 05:14:21 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	**ft_list_find(t_list **list, const t_list *ref,
						int (*cmp)(const t_list *, const t_list *))
{
	while (*list != NULL)
	{
		if ((*cmp)(*list, ref) == 0)
			return (list);
		list = &(*list)->next;
	}
	return (NULL);
}
