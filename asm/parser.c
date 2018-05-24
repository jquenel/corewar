/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 23:40:31 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 16:24:37 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ft_printf.h>
#include <libft_str.h>
#include <stdlib.h>
#include <unistd.h>
#include "ast.h"
#include "lexer.h"
#include "parser.h"

static const int	g_production_rules[][6] = {
	{Start, LineSeparator | TERMINAL_FLAG, -1},
	{ExpectComment, LineSeparator | TERMINAL_FLAG, Name, -1},
	{ExpectName, LineSeparator | TERMINAL_FLAG, Comment, -1},
	{ExpectComment, LineSeparator | TERMINAL_FLAG, -1},
	{Label, LineSeparator | TERMINAL_FLAG, Comment, -1},
	{ExpectName, LineSeparator | TERMINAL_FLAG, -1},
	{Label, LineSeparator | TERMINAL_FLAG, Name, -1},
	{StringLiteral | TERMINAL_FLAG, CommentCommand | TERMINAL_FLAG, -1},
	{StringLiteral | TERMINAL_FLAG, NameCommand | TERMINAL_FLAG, -1},
	{Instruction, LabelString | TERMINAL_FLAG, -1},
	{Instruction, -1},
	{-1},
	{Label, LineSeparator | TERMINAL_FLAG, OperandNext, Operand,
		Operator | TERMINAL_FLAG, -1},
	{Label, LineSeparator | TERMINAL_FLAG, -1},
	{OperandNext, Operand, SeparatorChar | TERMINAL_FLAG, -1},
	{-1},
	{Val, DirectChar | TERMINAL_FLAG, -1},
	{Val, -1},
	{Register | TERMINAL_FLAG, -1},
	{LabelVal | TERMINAL_FLAG, -1},
	{Number | TERMINAL_FLAG, -1}
};

static const int	g_parse_table[NON_TERMINAL_COUNT][TERMINAL_COUNT] = {
	{0, 2, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{3, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{5, -1, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{-1, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{10, -1, -1, -1, 9, 10, -1, -1, -1, -1, -1, 11},
	{13, -1, -1, -1, -1, 12, -1, -1, -1, -1, -1, -1},
	{15, -1, -1, -1, -1, -1, 14, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, 16, 18, 17, 17, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, 19, 20, -1}
};

static const char	*g_non_terminals[NON_TERMINAL_COUNT] = {
	"Start",
	"ExpectComment",
	"ExpectName",
	"Comment",
	"Name",
	"Label",
	"Instruction",
	"OperandNext",
	"Operand",
	"Val"
};

static const char	*g_terminals[TERMINAL_COUNT] = {
	"LineSeparator",
	"CommentCommand",
	"NameCommand",
	"StringLiteral",
	"LabelString",
	"Operator",
	"SeparatorChar",
	"DirectChar",
	"Register",
	"LabelVal",
	"Number",
	"EndOfFile"
};

static void			init_parser_state(t_parser_ctx *ctx)
{
	ft_memset(ctx->symbol_stack, 0, sizeof(ctx->symbol_stack));
	ctx->symbol_stack[0] = EndOfFile | TERMINAL_FLAG;
	ctx->symbol_stack[1] = Start;
	ctx->stack_offset = 1;
}

static void			push_production_rule(t_parser_ctx *ctx, int rule_id)
{
	int	i;
	int	symbol;

	i = 0;
	while (g_production_rules[rule_id][i] != -1)
	{
		symbol = g_production_rules[rule_id][i++];
		ctx->symbol_stack[++ctx->stack_offset] = symbol;
	}
}

static int			check_symbol_match(int symbol, t_token *token)
{
	if (!(symbol & TERMINAL_FLAG)
		|| symbol != (token->terminal | TERMINAL_FLAG))
	{
		ft_dprintf(
			STDERR_FILENO,
			"Syntax error at line %u: got %s as %s, expected %s.\n",
			token->line_nbr, token->str, g_terminals[token->terminal],
			symbol & TERMINAL_FLAG
			? g_terminals[symbol & ~TERMINAL_FLAG]
			: g_non_terminals[symbol]);
		return (0);
	}
	return (1);
}

static int			parse_fd(t_lexer_ctx *lexer_ctx, t_parser_ctx *parser_ctx,
							t_token *token, t_ast *ast)
{
	int		current_symbol;

	while (get_next_token(lexer_ctx, token))
	{
		current_symbol = parser_ctx->symbol_stack[parser_ctx->stack_offset--];
		while (!(current_symbol & TERMINAL_FLAG)
				&& g_parse_table[current_symbol][token->terminal] >= 0)
		{
			push_production_rule(
				parser_ctx, g_parse_table[current_symbol][token->terminal]);
			current_symbol =
				parser_ctx->symbol_stack[parser_ctx->stack_offset--];
		}
		if (!check_symbol_match(current_symbol, token))
			return (0);
		if (token->terminal == EndOfFile)
			return (1);
		push_to_ast(ast, token);
		free(token->str);
		token->str = NULL;
	}
	ft_dprintf(STDERR_FILENO, "I/O error reading source file.\n");
	return (0);
}

int					parse(const char *filename, t_ast *ast)
{
	int				ret;
	t_lexer_ctx		lexer_ctx;
	t_parser_ctx	parser_ctx;
	t_token			token;

	if ((lexer_ctx.fd = open(filename, O_RDONLY)) < 0)
	{
		ft_dprintf(STDERR_FILENO, "Could not open source file.\n");
		return (0);
	}
	init_lexer_state(&lexer_ctx);
	init_parser_state(&parser_ctx);
	token.str = NULL;
	ret = parse_fd(&lexer_ctx, &parser_ctx, &token, ast);
	free(token.str);
	free(lexer_ctx.line);
	close(lexer_ctx.fd);
	return (ret);
}
