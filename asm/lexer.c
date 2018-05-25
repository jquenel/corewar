/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 23:40:43 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 23:54:00 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_array.h>
#include <libft_io.h>
#include <libft_std.h>
#include <libft_str.h>
#include <stdlib.h>
#include <unistd.h>
#include "lexer.h"
#include "op.h"
#include "xmalloc.h"

static int			read_string_literal_aux(t_lexer_ctx *ctx)
{
	int		ret;
	char	*line;
	size_t	line_len;
	char	*new_line;

	if (ctx->line[ctx->read] == '"'
		|| (ret = get_next_line(ctx->fd, &line)) == 0)
		return (0);
	if (ret < 0)
		return (-1);
	line_len = ft_strlen(line);
	new_line = (char *)xmalloc(ctx->read + line_len + 2);
	ft_memcpy(new_line, ctx->line, ctx->read);
	new_line[ctx->read] = '\n';
	ft_memcpy(new_line + ctx->read + 1, line, line_len);
	new_line[ctx->read + 1 + line_len] = '\0';
	free(ctx->line);
	free(line);
	ctx->line = new_line;
	++ctx->line_nbr;
	return (1);
}

static int			read_string_literal(t_lexer_ctx *ctx, t_token *token)
{
	size_t	read_start;
	int		ret;

	read_start = ++ctx->read;
	while (1)
	{
		while (ctx->line[ctx->read] != '\0' && ctx->line[ctx->read] != '"')
			++ctx->read;
		ret = read_string_literal_aux(ctx);
		if (ret < 0)
			return (0);
		if (ret == 0)
			break ;
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
		if (!ft_strisstr(str + 1, LABEL_CHARS))
			return (Unknown);
		ft_strcpy(str, str + 1);
		return (LabelVal);
	}
	if (str[ft_strlen(str) - 1] == LABEL_CHAR)
	{
		str[ft_strlen(str) - 1] = '\0';
		if (!ft_strisstr(str, LABEL_CHARS))
			return (Unknown);
		return (LabelString);
	}
	if (ft_strforall(str, ft_isdigit)
		|| (str[0] == '-' && ft_strforall(str + 1, ft_isdigit)))
		return (Number);
	if (*str == 'r' && ft_int_of_string(str + 1, NULL))
		return (Register);
	return (Operator);
}

static int			get_next_token_on_line(t_lexer_ctx *ctx, t_token *token)
{
	size_t	read_start;

	token->line_nbr = ctx->line_nbr;
	if (is_stop_char(ctx->line[ctx->read]))
	{
		if (ctx->line[ctx->read] == COMMENT_CHAR
			|| ctx->line[ctx->read] == COMMENT_CHAR_AUX)
			return (lexer_get_next_line(ctx, token));
		if (ctx->line[ctx->read] == '"')
			return (read_string_literal(ctx, token));
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
	if (ctx->line == NULL)
	{
		if (!lexer_get_next_line(ctx, token))
			return (0);
		if (ctx->line == NULL)
		{
			token->terminal = EndOfFile;
			return (1);
		}
	}
	skip_space(ctx);
	if (ctx->line[ctx->read] == '\0')
		return (lexer_get_next_line(ctx, token));
	return (get_next_token_on_line(ctx, token));
}
