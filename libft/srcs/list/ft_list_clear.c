/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:07:32 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 05:58:39 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_clear(t_list **list, void (*freef)(t_list *))
{
	t_list	*iter;
	t_list	*next;

	iter = *list;
	*list = NULL;
	while (iter != NULL)
	{
		next = iter->next;
		if (freef != NULL)
			freef(iter);
		iter = next;
	}
}
