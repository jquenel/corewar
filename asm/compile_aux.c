/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:02:20 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 14:15:43 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_std.h>
#include <libft_str.h>
#include "ast.h"
#include "compile.h"
#include "op.h"
#include "xmalloc.h"

t_core	*make_core(t_ast *ast, size_t prog_size)
{
	t_core	*core;

	core = (t_core *)xmalloc(sizeof(*core) + prog_size);
	core->offset = 0;
	core->header.magic = COREWAR_EXEC_MAGIC;
	ft_strncpy(core->header.prog_name, ast->name, PROG_NAME_LENGTH);
	core->header.null1 = 0;
	core->header.prog_size = ft_htonl(prog_size);
	ft_strncpy(core->header.comment, ast->comment, COMMENT_LENGTH);
	core->header.null2 = 0;
	return (core);
}
