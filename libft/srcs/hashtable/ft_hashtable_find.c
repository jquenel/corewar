/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_find.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:11:21 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 22:49:32 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hashtable.h"
#include "internal/hashtable.h"

void	*ft_hashtable_find(t_hashtable *hashtable, const void *ref_data)
{
	size_t	hash;
	size_t	offset;
	t_table	**table;
	void	*ret;

	hash = (*hashtable->hashfun)(ref_data);
	offset = hashtable_table_find(
		hashtable->table, hash, hashtable->compfun, ref_data);
	if (offset != (size_t)-1)
		return (hashtable->table->data[offset]);
	table = &hashtable->table;
	while (*table != NULL)
	{
		offset = hashtable_table_find(
			*table, hash, hashtable->compfun, ref_data);
		if (offset != (size_t)-1)
		{
			ret = (*table)->data[offset];
			hashtable_move_elements(hashtable, table, offset);
			return (ret);
		}
		table = &(*table)->older_table;
	}
	return (NULL);
}
