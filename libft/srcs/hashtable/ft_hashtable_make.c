/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_make.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:57:39 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 19:40:46 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_hashtable.h"
#include "internal/hashtable.h"

t_hashtable	*ft_hashtable_make(t_hashfun hashfun, t_compfun compfun,
								size_t initial_size)
{
	t_hashtable	*hashtable;

	hashtable = (t_hashtable *)malloc(sizeof(*hashtable));
	if (hashtable == NULL)
		return (NULL);
	hashtable->hashfun = hashfun;
	hashtable->compfun = compfun;
	hashtable->table = hashtable_make_table(initial_size);
	if (hashtable->table == NULL)
	{
		free(hashtable);
		return (NULL);
	}
	return (hashtable);
}
