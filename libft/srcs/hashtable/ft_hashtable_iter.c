/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_iter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:26:25 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/13 18:41:15 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/hashtable.h"
#include "libft_hashtable.h"

void	ft_hashtable_iter(t_hashtable *hashtable, void (*f)(void *, void *),
							void *ctx)
{
	t_table	*table;
	size_t	i;

	table = hashtable->table;
	while (table != NULL)
	{
		i = 0;
		while (i < table->table_size)
		{
			if (table->data[i] != NULL)
				(*f)(table->data[i], ctx);
			++i;
		}
		table = table->older_table;
	}
}
