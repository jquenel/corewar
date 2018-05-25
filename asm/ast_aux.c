/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 20:35:47 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 16:33:04 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_list.h>
#include <stdlib.h>
#include "ast.h"

void		init_ast(t_ast *ast)
{
	ast->elements = NULL;
	ast->name = NULL;
	ast->comment = NULL;
}

static void	free_operand(t_operand_list *oper)
{
	free(oper->str);
	free(oper);
}

static void	free_element(t_element_list *elem)
{
	if (elem->type == LabelElem)
		free(elem->u.label.name);
	else
	{
		free(elem->u.instruction.operator);
		ft_list_clear((t_list **)&elem->u.instruction.operands,
						(void (*)(t_list *))free_operand);
	}
	free(elem);
}

void		destroy_ast(t_ast *ast)
{
	free(ast->name);
	free(ast->comment);
	ft_list_clear((t_list **)&ast->elements, (void (*)(t_list *))free_element);
}
