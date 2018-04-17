/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:39:36 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 23:10:43 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/hashtable.h"
#include "libft_hashtable.h"

t_table	*hashtable_make_table(size_t size)
{
	t_table	*table;
	size_t	i;

	table = (t_table *)malloc(sizeof(*table) + sizeof(void *) * size);
	if (table == NULL)
		return (NULL);
	table->older_table = NULL;
	table->element_count = 0;
	table->table_size = size;
	i = 0;
	while (i < size)
		table->data[i++] = NULL;
	return (table);
}

size_t	hashtable_table_find(t_table *table, size_t hash, t_compfun compfun,
							const void *ref_data)
{
	size_t	i;

	i = hash % table->table_size;
	while (table->data[i] != NULL)
	{
		if ((*compfun)(ref_data, table->data[i]) == 0)
			return (i);
		i = TABLE_SUCC(i, table);
	}
	return ((size_t)-1);
}

void	hashtable_move_elements(t_hashtable *hashtable, t_table **table,
								size_t offset)
{
	void	*elem;
	t_table	*to_free;

	elem = (*table)->data[offset];
	if (elem == NULL)
	{
		if ((*table)->element_count == 0)
		{
			to_free = (void *)*table;
			*table = (*table)->older_table;
			free(to_free);
		}
		return ;
	}
	(*table)->data[offset] = NULL;
	--(*table)->element_count;
	hashtable_move_elements(hashtable, table, TABLE_SUCC(offset, *table));
	ft_hashtable_insert(hashtable, elem);
}

void	hashtable_move_elements_fast(t_table *table, size_t offset,
									t_hashfun hashfun)
{
	size_t	new_offset;

	while (table->data[offset] != NULL)
	{
		new_offset = (*hashfun)(table->data[offset]) % table->table_size;
		while (new_offset != offset)
		{
			if (table->data[new_offset] == NULL)
			{
				table->data[new_offset] = table->data[offset];
				table->data[offset] = NULL;
				break ;
			}
			new_offset = TABLE_SUCC(new_offset, table);
		}
		offset = TABLE_SUCC(offset, table);
	}
}
