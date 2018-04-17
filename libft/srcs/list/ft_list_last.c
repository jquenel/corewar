/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:42:21 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 04:59:01 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	**ft_list_last(t_list **list)
{
	if (*list == NULL)
		return (NULL);
	while ((*list)->next != NULL)
		list = &(*list)->next;
	return (list);
}
