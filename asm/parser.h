/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 23:40:11 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/28 16:26:14 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ast.h"

typedef enum e_non_terminal	t_non_terminal;
enum	e_non_terminal
{
	Start,
	ExpectComment,
	ExpectName,
	Comment,
	Name,
	Label,
	Instruction,
	OperandNext,
	Operand,
	Val,
	NON_TERMINAL_COUNT
};

typedef struct s_parser_ctx	t_parser_ctx;
struct	s_parser_ctx
{
	int	symbol_stack[16];
	int	stack_offset;
};

int		parse(const char *filename, t_ast *ast);

#endif
