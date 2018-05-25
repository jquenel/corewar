/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 00:59:48 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/21 22:22:47 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_list.h>
#include "ast.h"
#include "lexer.h"
#include "xmalloc.h"

static void	push_label_elem(t_ast *ast, t_token *token)
{
	t_element_list	*elem;

	elem = (t_element_list *)xmalloc(sizeof(*elem));
	elem->next = ast->elements;
	elem->type = LabelElem;
	elem->line_nbr = token->line_nbr;
	elem->u.label.name = token->str;
	token->str = NULL;
	ast->elements = elem;
}

static void	push_instruction_elem(t_ast *ast, t_token *token)
{
	t_element_list	*elem;

	elem = (t_element_list *)xmalloc(sizeof(*elem));
	elem->next = ast->elements;
	elem->type = InstructionElem;
	elem->line_nbr = token->line_nbr;
	elem->u.instruction.operator = token->str;
	token->str = NULL;
	elem->u.instruction.operands = NULL;
	ast->elements = elem;
}

static void	add_operand(t_ast *ast, t_token *token, int direct_flag)
{
	t_operand_list	*operand;

	operand = (t_operand_list *)xmalloc(sizeof(*operand));
	operand->next = NULL;
	operand->type = token->terminal - Register;
	operand->direct_flag = direct_flag;
	operand->str = token->str;
	token->str = NULL;
	*ft_list_last((t_list **)&ast->elements->u.instruction.operands) =
		(t_list *)operand;
}

void		push_to_ast(t_ast *ast, t_token *token)
{
	static t_command	command = CommandNone;
	static int			direct_flag = 0;

	if (token->terminal == NameCommand)
		command = CommandName;
	else if (token->terminal == CommentCommand)
		command = CommandComment;
	else if (token->terminal == StringLiteral)
	{
		*(command == CommandName ? &ast->name : &ast->comment) = token->str;
		token->str = NULL;
	}
	else if (token->terminal == LabelString)
		push_label_elem(ast, token);
	else if (token->terminal == Operator)
		push_instruction_elem(ast, token);
	else if (token->terminal == DirectChar)
		direct_flag = 1;
	else if (token->terminal == Register || token->terminal == LabelVal
			|| token->terminal == Number)
	{
		add_operand(ast, token, direct_flag);
		direct_flag = 0;
	}
}
