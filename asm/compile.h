/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:02:57 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 14:13:08 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPILE_H
# define COMPILE_H

# include <libft_hashtable.h>
# include "ast.h"
# include "op.h"

typedef struct s_core	t_core;
struct	s_core
{
	size_t		offset;
	t_header	header;
	char		core[];
};

t_core	*make_core(t_ast *ast, size_t prog_size);
int		compile(t_ast *ast, t_hashtable *labels, const char *filename,
				size_t prog_size);

#endif
