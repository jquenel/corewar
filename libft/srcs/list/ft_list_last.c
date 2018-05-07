/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:42:21 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/07 02:41:24 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	**ft_list_last(t_list **list)
{
	t_list	*iter;

	iter = (t_list *)list;
	while (iter->next != NULL)
		iter = iter->next;
	return (&iter->next);
}
