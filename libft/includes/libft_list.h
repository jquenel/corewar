/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:36:18 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/26 05:34:45 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include <stddef.h>

typedef struct s_list	t_list;
struct	s_list
{
	t_list	*next;
};

size_t	ft_list_length(const t_list *list);
t_list	**ft_list_at(t_list **list, size_t index);
t_list	**ft_list_last(t_list **list);
void	ft_list_insert_after(t_list *node, t_list *data);
void	ft_list_insert_before(t_list **node, t_list *data);
void	ft_list_accumulate(t_list **list, t_list **acc);
void	ft_list_remove(t_list **node, void (*freef)(t_list *));
void	ft_list_clear(t_list **list, void (*freef)(t_list *));
t_list	**ft_list_find(t_list **list, const t_list *ref,
						int (*cmp)(const t_list *, const t_list *));
void	ft_list_foreach(t_list **list, void (*f)(t_list **, void *), void *ctx);
void	ft_list_merge(t_list **list1, t_list *list2);
void	ft_list_reverse(t_list **list);
void	ft_list_sort(t_list **list, int (*cmp)(const t_list *, const t_list *));
void	ft_list_merge_sorted(t_list **list1, t_list *list2,
							int (*cmp)(const t_list *, const t_list *));

#endif
