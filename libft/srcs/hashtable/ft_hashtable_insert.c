/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:39:40 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 23:25:43 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"
#include "internal/hashtable.h"

int	ft_hashtable_insert(t_hashtable *hashtable, void *data)
{
	size_t	offset;
	t_table	*table;

	table = hashtable->table;
	if (table->table_size * RESIZE_THRESHOLD <= table->element_count)
	{
		table = hashtable_make_table(table->table_size * GROWTH_FACTOR);
		if (table == NULL)
			return (0);
		table->older_table = hashtable->table;
		hashtable->table = table;
	}
	offset = (*hashtable->hashfun)(data) % table->table_size;
	while (table->data[offset] != NULL)
		offset = TABLE_SUCC(offset, table);
	table->data[offset] = data;
	++table->element_count;
	return (1);
}
