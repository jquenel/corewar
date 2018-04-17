/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_hashtable.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:17:01 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/17 17:33:15 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_HASHTABLE_H
# define LIBFT_HASHTABLE_H

# include <stddef.h>

# define RESIZE_THRESHOLD 3 / 4
# define GROWTH_FACTOR 2

typedef size_t(*t_hashfun)(const void *);
typedef int(*t_compfun)(const void *, const void *);

typedef struct	s_table
{
	struct s_table	*older_table;
	size_t			element_count;
	size_t			table_size;
	void			*data[];
}				t_table;

typedef struct	s_hashtable
{
	t_hashfun	hashfun;
	t_compfun	compfun;
	t_table		*table;
}				t_hashtable;

t_hashtable		*ft_hashtable_make(t_hashfun hashfun, t_compfun compfun,
									size_t initial_size);
int				ft_hashtable_insert(t_hashtable *hashtable, void *data);
void			*ft_hashtable_find(t_hashtable *hashtable,
									const void *ref_data);
void			*ft_hashtable_remove(t_hashtable *hashtable,
									const void *ref_data);
void			ft_hashtable_iter(t_hashtable *hashtable,
									void (*f)(void *, void *), void *ctx);
void			ft_hashtable_destroy(t_hashtable *hashtable,
									void (*freef)(void *));
size_t			ft_hashfun_int(const void *data);
int				ft_compfun_int(const void *i1, const void *i2);
size_t			ft_hashfun_string(const void *data);
int				ft_compfun_string(const void *str1, const void *str2);

#endif
