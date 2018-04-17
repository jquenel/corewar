/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_accumulate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 05:36:02 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 05:38:34 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_accumulate(t_list **list, t_list **acc)
{
	t_list	*next;

	next = (*list)->next;
	(*list)->next = *acc;
	*acc = *list;
	*list = next;
}
