/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_array.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:15:00 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/05 01:01:00 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARRAY_H
# define LIBFT_ARRAY_H

# include <stddef.h>

typedef void	*t_array;

t_array	ft_array_create(size_t size);
size_t	ft_array_length(const t_array array);
void	ft_array_iter(t_array array, size_t item_size, void (*iterf)(void *));
void	ft_array_iter_ptr_item(t_array array, void (*iterf)(void *));
void	ft_array_delete(t_array array);

#endif
