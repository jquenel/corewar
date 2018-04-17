/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:41:04 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 05:28:44 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_merge_sorted(t_list **list1, t_list *list2,
							int (*cmp)(const t_list *, const t_list *))
{
	t_list	*elem;
	t_list	*next;

	if (list2 == NULL)
		return ;
	elem = (t_list *)list1;
	while (elem->next != NULL)
	{
		if ((*cmp)(elem->next, list2) > 0)
		{
			next = list2;
			list2 = list2->next;
			next->next = elem->next;
			elem->next = next;
			if (list2 == NULL)
				return ;
		}
		elem = elem->next;
	}
	elem->next = list2;
}
