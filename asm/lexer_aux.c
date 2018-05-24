/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 23:42:52 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 18:54:41 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>
#include "lexer.h"
#include "op.h"

int		is_stop_char(int c)
{
	return (c == COMMENT_CHAR || c == COMMENT_CHAR_AUX
			|| c == DIRECT_CHAR || c == SEPARATOR_CHAR
			|| c == '"' || c == '\0' || ft_isspace(c));
}

void	skip_space(t_lexer_ctx *ctx)
{
	while (ft_isspace(ctx->line[ctx->read]))
		++ctx->read;
}

void	init_lexer_state(t_lexer_ctx *ctx)
{
	ctx->line_nbr = 0;
	ctx->line = NULL;
	ctx->read = 0;
}
