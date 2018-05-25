/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 00:59:42 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 16:33:34 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <libft_list.h>
# include "lexer.h"

typedef enum e_element_type	t_element_type;
enum	e_element_type
{
	LabelElem,
	InstructionElem
};

typedef struct s_label_element	t_label_element;
struct	s_label_element
{
	char	*name;
};

typedef enum e_operand_type	t_operand_type;
enum	e_operand_type
{
	RegisterOper,
	LabelOper,
	NumberOper
};

typedef struct s_operand_list	t_operand_list;
struct	s_operand_list
{
	t_operand_list	*next;
	t_operand_type	type:31;
	int				direct_flag:1;
	char			*str;
};

typedef struct s_instruction_element	t_instruction_element;
struct	s_instruction_element
{
	size_t			offset;
	char			*operator;
	t_operand_list	*operands;
};

union	u_element
{
	t_label_element			label;
	t_instruction_element	instruction;
};

typedef struct s_element_list	t_element_list;
struct	s_element_list
{
	t_element_list	*next;
	t_element_type	type;
	unsigned int	line_nbr;
	union u_element	u;
};

typedef struct s_ast	t_ast;
struct	s_ast
{
	char			*name;
	char			*comment;
	t_element_list	*elements;
};

typedef enum e_command	t_command;
enum	e_command
{
	CommandNone = -1,
	CommandName,
	CommandComment
};

void	init_ast(t_ast *ast);
void	destroy_ast(t_ast *ast);
void	push_to_ast(t_ast *ast, t_token *token);

#endif
