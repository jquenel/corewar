/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 23:42:52 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 23:48:43 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_io.h>
#include <libft_str.h>
#include <stdlib.h>
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

int		lexer_get_next_line(t_lexer_ctx *ctx, t_token *token)
{
	int	ret;

	token->line_nbr = ctx->line_nbr++;
	free(ctx->line);
	ctx->read = 0;
	if ((ret = get_next_line(ctx->fd, &ctx->line)) == -1)
		return (0);
	if (ret == 0)
		ctx->line = NULL;
	token->terminal = LineSeparator;
	return (1);
}

void	init_lexer_state(t_lexer_ctx *ctx)
{
	ctx->line_nbr = 0;
	ctx->line = NULL;
	ctx->read = 0;
}
