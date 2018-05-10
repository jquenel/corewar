/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:02:57 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/10 00:38:08 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPILE_H
# define COMPILE_H

# include <libft_hashtable.h>
# include "ast.h"

int	compile(t_ast *ast, t_hashtable *labels, const char *filename,
			size_t prog_size);

#endif
