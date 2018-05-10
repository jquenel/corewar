/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 23:40:13 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/09 02:17:46 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <libft_array.h>
# include <stddef.h>

# define TERMINAL_FLAG (1 << 24)

typedef enum e_terminal	t_terminal;
enum	e_terminal
{
	Unknown = -1,
	LineSeparator,
	CommentCommand,
	NameCommand,
	StringLiteral,
	LabelString,
	Operator,
	SeparatorChar,
	DirectChar,
	Register,
	LabelVal,
	Number,
	EndOfFile,
	TERMINAL_COUNT
};

typedef struct s_token	t_token;
struct	s_token
{
	t_terminal	terminal;
	char		*str;
};

typedef struct s_lexer_ctx	t_lexer_ctx;
struct	s_lexer_ctx
{
	int		fd;
	char	*line;
	size_t	read;
};

void	init_lexer_state(t_lexer_ctx *ctx, int fd);
int		get_next_token(t_lexer_ctx *ctx, t_token *token);

#endif
