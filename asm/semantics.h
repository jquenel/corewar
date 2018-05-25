/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantics.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:58:34 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 19:47:18 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEMANTICS_H
# define SEMANTICS_H

# include <libft_hashtable.h>
# include <stddef.h>
# include "ast.h"
# include "op.h"

typedef struct s_label_value	t_label_value;
struct	s_label_value
{
	const char		*str;
	size_t			offset;
	unsigned int	line_nbr;
};

int		check_operand_type(const t_element_list *elem, unsigned int id,
							const t_op *op);
int		check_label_exists(const t_element_list *elem, unsigned int id,
							t_hashtable *labels_hashtable, int ret);
int		check_register_number(const t_element_list *elem, unsigned int id,
								int ret);
int		check_semantics(t_ast *ast, t_hashtable *labels_hashtable,
						size_t *prog_size);

#endif
