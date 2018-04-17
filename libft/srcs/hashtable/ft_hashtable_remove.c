/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_remove.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:05:15 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 23:52:32 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_hashtable.h"
#include "internal/hashtable.h"

static void	*remove_one(t_table *table, size_t hash, t_compfun compfun,
						const void *ref_data)
{
	size_t	offset;
	void	*ret;

	offset = hashtable_table_find(table, hash, compfun, ref_data);
	if (offset == (size_t)-1)
		return (NULL);
	ret = table->data[offset];
	table->data[offset] = NULL;
	--table->element_count;
	return (ret);
}

void		*ft_hashtable_remove(t_hashtable *hashtable, const void *ref_data)
{
	size_t	hash;
	t_table	**table;
	void	*ret;

	hash = (*hashtable->hashfun)(ref_data);
	ret = remove_one(hashtable->table, hash, hashtable->compfun, ref_data);
	if (ret != NULL)
	{
		hashtable_move_elements_fast(hashtable->table,
			TABLE_SUCC(hash, hashtable->table), hashtable->hashfun);
		return (ret);
	}
	table = &hashtable->table;
	while (*table != NULL)
	{
		ret = remove_one(*table, hash, hashtable->compfun, ref_data);
		if (ret != NULL)
		{
			hashtable_move_elements(hashtable, table, TABLE_SUCC(hash, *table));
			return (ret);
		}
		table = &(*table)->older_table;
	}
	return (NULL);
}
