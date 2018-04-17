/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:22:27 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 05:17:36 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_foreach(t_list **list, void (*f)(t_list **, void *), void *ctx)
{
	t_list	**next;

	while (*list != NULL)
	{
		next = &(*list)->next;
		(*f)(list, ctx);
		list = next;
	}
}
