/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 23:40:43 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/17 23:52:32 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>
#include <libft_io.h>
#include <libft_str.h>
#include <stdlib.h>
#include <unistd.h>
#include "lexer.h"
#include "op.h"
#include "xmalloc.h"

static int			read_user_comment(t_lexer_ctx *ctx, t_token *token)
{
	int	ret;

	free(ctx->line);
	ctx->read = 0;
	if ((ret = get_next_line(ctx->fd, &ctx->line)) == -1)
		return (0);
	if (ret == 0)
		ctx->line = NULL;
	token->terminal = LineSeparator;
	return (1);
}

static int			read_string_literal(t_lexer_ctx *ctx, t_token *token)
{
	size_t	read_start;

	read_start = ++ctx->read;
	while (ctx->line[ctx->read] != '\0' && ctx->line[ctx->read] != '"')
	{
		if (ctx->line[ctx->read] == '\\' && ctx->line[ctx->read + 1] != '\0')
			++ctx->read;
		++ctx->read;
	}
	token->str = (char *)xmalloc(ctx->read - read_start + 1);
	ft_strncpy(token->str, ctx->line + read_start, ctx->read - read_start);
	token->str[ctx->read - read_start] = '\0';
	if (ctx->line[ctx->read] == '"')
	{
		++ctx->read;
		token->terminal = StringLiteral;
	}
	else
		token->terminal = Unknown;
	return (1);
}

static t_terminal	identify_literal(char *str)
{
	if (ft_strcmp(str, COMMENT_CMD_STRING) == 0)
		return (CommentCommand);
	if (ft_strcmp(str, NAME_CMD_STRING) == 0)
		return (NameCommand);
	if (*str == LABEL_CHAR)
	{
		ft_strcpy(str, str + 1);
		return (LabelVal);
	}
	if (str[ft_strlen(str) - 1] == LABEL_CHAR)
	{
		str[ft_strlen(str) - 1] = '\0';
		return (LabelString);
	}
	if (*str == 'r')
		return (Register);
	if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(str[1])))
		return (Number);
	return (Operator);
}

static int			get_next_token_on_line(t_lexer_ctx *ctx, t_token *token)
{
	size_t	read_start;

	if (is_stop_char(ctx->line[ctx->read]))
	{
		if (ctx->line[ctx->read] == '"')
			return (read_string_literal(ctx, token));
		if (ctx->line[ctx->read] == COMMENT_CHAR)
			return (read_user_comment(ctx, token));
		if (ctx->line[ctx->read++] == DIRECT_CHAR)
			token->terminal = DirectChar;
		else
			token->terminal = SeparatorChar;
		return (1);
	}
	read_start = ctx->read;
	while (!is_stop_char(ctx->line[ctx->read]))
		++ctx->read;
	token->str = (char *)xmalloc(ctx->read - read_start + 1);
	ft_strncpy(token->str, ctx->line + read_start, ctx->read - read_start);
	token->str[ctx->read - read_start] = '\0';
	token->terminal = identify_literal(token->str);
	return (1);
}

int					get_next_token(t_lexer_ctx *ctx, t_token *token)
{
	int		ret;

	if (ctx->line == NULL)
	{
		if ((ret = get_next_line(ctx->fd, &ctx->line)) == -1)
			return (0);
		if (ret == 0)
		{
			token->terminal = EndOfFile;
			return (1);
		}
	}
	skip_space(ctx);
	if (ctx->line[ctx->read] == '\0')
	{
		free(ctx->line);
		ctx->read = 0;
		if ((ret = get_next_line(ctx->fd, &ctx->line)) == -1)
			return (0);
		if (ret == 0)
			ctx->line = NULL;
		token->terminal = LineSeparator;
		return (1);
	}
	return (get_next_token_on_line(ctx, token));
}
