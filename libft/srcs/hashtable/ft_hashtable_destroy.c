/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:26:25 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/13 18:40:47 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "internal/hashtable.h"
#include "libft_hashtable.h"

void	ft_hashtable_destroy(t_hashtable *hashtable, void (*freef)(void *))
{
	t_table	*table;
	t_table	*table_next;
	size_t	i;

	table = hashtable->table;
	while (table != NULL)
	{
		i = 0;
		while (i < table->table_size)
		{
			if (table->data[i] != NULL)
				(*freef)(table->data[i]);
			++i;
		}
		table_next = table->older_table;
		free(table);
		table = table_next;
	}
	free(hashtable);
}
