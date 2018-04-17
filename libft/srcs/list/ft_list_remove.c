/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:59:26 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 05:58:53 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_remove(t_list **node, void (*freef)(t_list *))
{
	t_list	*next;

	next = (*node)->next;
	if (freef != NULL)
		freef(*node);
	*node = next;
}
