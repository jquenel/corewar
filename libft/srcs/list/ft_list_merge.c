/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:18:44 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 05:20:25 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_merge(t_list **list1, t_list *list2)
{
	if (*list1 == NULL)
		*list1 = list2;
	else
		(*ft_list_last(list1))->next = list2;
}
