/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantics.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:58:34 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/21 19:10:27 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEMANTICS_H
# define SEMANTICS_H

# include <libft_hashtable.h>
# include <stddef.h>
# include "ast.h"

typedef struct s_label_value	t_label_value;
struct	s_label_value
{
	const char		*str;
	size_t			offset;
	unsigned int	line_nbr;
};

int		check_semantics(t_ast *ast, t_hashtable **labels_hashtable,
						size_t *prog_size);

#endif
