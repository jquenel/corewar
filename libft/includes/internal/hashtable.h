/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:37:12 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 23:22:49 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_HASHTABLE_H
# define INTERNAL_HASHTABLE_H

# include "libft_hashtable.h"

# ifndef NULL
#  define NULL ((void *)0)
# endif

# define TABLE_SUCC(o, t) (((o) + 1) % (t)->table_size)

t_table	*hashtable_make_table(size_t size);
size_t	hashtable_table_find(t_table *table, size_t hash, t_compfun compfun,
							const void *ref_data);
void	hashtable_move_elements(t_hashtable *hashtable, t_table **table,
								size_t offset);
void	hashtable_move_elements_fast(t_table *table, size_t offset,
									t_hashfun hashfun);

#endif
