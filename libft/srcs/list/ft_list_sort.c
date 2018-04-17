/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:28:16 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 22:16:44 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

static size_t	ft_list_split(t_list *list, t_list **acc1, t_list **acc2)
{
	size_t	count;

	*acc1 = NULL;
	*acc2 = NULL;
	count = 0;
	while (list != NULL)
	{
		ft_list_accumulate(&list, acc1);
		if (list == NULL)
			return (count + 1);
		ft_list_accumulate(&list, acc2);
		count += 2;
	}
	return (count);
}

static void		ft_small_list_sort(t_list **list,
									int (*cmp)(const t_list *, const t_list *))
{
	t_list	*sorted;
	t_list	*elem;

	sorted = NULL;
	while (*list != NULL)
	{
		elem = *list;
		*list = (*list)->next;
		elem->next = NULL;
		ft_list_merge_sorted(&sorted, elem, cmp);
	}
	*list = sorted;
}

void			ft_list_sort(t_list **list,
							int (*cmp)(const t_list *, const t_list *))
{
	t_list	*list1;
	t_list	*list2;
	size_t	count;

	count = ft_list_split(*list, &list1, &list2);
	if (count < 16)
	{
		ft_small_list_sort(&list1, cmp);
		ft_small_list_sort(&list2, cmp);
	}
	else
	{
		ft_list_sort(&list1, cmp);
		ft_list_sort(&list2, cmp);
	}
	ft_list_merge_sorted(&list1, list2, cmp);
	*list = list1;
}
