/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:16:47 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 05:21:45 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_reverse(t_list **list)
{
	t_list	*rev_list;
	t_list	*next;

	rev_list = NULL;
	while (*list != NULL)
	{
		next = (*list)->next;
		(*list)->next = rev_list;
		rev_list = *list;
		*list = next;
	}
	*list = rev_list;
}
