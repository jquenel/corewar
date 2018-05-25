/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:58:27 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 19:47:51 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft_hashtable.h>
#include <libft_str.h>
#include <unistd.h>
#include "ast.h"
#include "op.h"
#include "semantics.h"
#include "utils.h"
#include "xmalloc.h"

static int	record_label(const t_element_list *elem, size_t offset,
						t_hashtable *labels_hashtable)
{
	const t_label_element	*label_elem;
	t_label_value			*label;

	label_elem = &elem->u.label;
	if ((label = ft_hashtable_find(labels_hashtable, &label_elem->name))
		!= NULL)
	{
		ft_dprintf(
			STDERR_FILENO, "Duplicate label \"%s\" at line %u, first occurence "
			"at line %u.\n", label_elem->name, elem->line_nbr, label->line_nbr);
		return (0);
	}
	label = (t_label_value *)xmalloc(sizeof(*label));
	label->str = label_elem->name;
	label->offset = offset;
	label->line_nbr = elem->line_nbr;
	if (!ft_hashtable_insert(labels_hashtable, label))
		die_oom();
	return (1);
}

static int	check_operand(const t_element_list *elem, unsigned int id,
							const t_op *op, t_hashtable *labels_hashtable)
{
	const t_operand_list	*oper;
	int						ret;

	oper = (const t_operand_list *)
		*ft_list_at((t_list **)&elem->u.instruction.operands, id);
	ret = check_operand_type(elem, id, op);
	if (oper->type == LabelOper)
		ret = check_label_exists(elem, id, labels_hashtable, ret);
	if (oper->type == RegisterOper)
		ret = check_register_number(elem, id, ret);
	return (ret);
}

static int	check_instruction(const t_element_list *elem,
								t_hashtable *labels_hashtable, const t_op *op,
								int ret)
{
	const t_operand_list	*iter;
	unsigned int			i;

	iter = elem->u.instruction.operands;
	i = 0;
	while (i < op->nbr_arg && iter != NULL)
	{
		ret = check_operand(elem, i, op, labels_hashtable) && ret;
		++i;
		iter = iter->next;
	}
	if (i < op->nbr_arg || iter != NULL)
	{
		ft_dprintf(
			STDERR_FILENO, "Operator \"%s\" at line %u expects %u arguments.\n",
			op->mnemo, elem->line_nbr, op->nbr_arg);
		ret = 0;
	}
	return (ret);
}

static int	check_instructions_semantics(t_ast *ast,
										t_hashtable *labels_hashtable, int ret)
{
	t_element_list	*iter;
	const t_op		*op;

	iter = ast->elements;
	while (iter != NULL)
	{
		if (iter->type == InstructionElem)
		{
			op = g_op_tab + mnemo_id(iter->u.instruction.operator);
			if (op == g_op_tab - 1)
			{
				ft_dprintf(
					STDERR_FILENO, "Unknown operator \"%s\" at line %u.\n",
					iter->u.instruction.operator, iter->line_nbr);
				ret = 0;
			}
			else
				ret = check_instruction(iter, labels_hashtable, op, ret);
		}
		iter = iter->next;
	}
	return (ret);
}

int			check_semantics(t_ast *ast, t_hashtable *labels_hashtable,
							size_t *prog_size)
{
	int				ret;
	t_element_list	*iter;
	size_t			offset;

	ret = 1;
	iter = ast->elements;
	offset = 0;
	while (iter != NULL)
	{
		if (iter->type == LabelElem)
			ret = record_label(iter, offset, labels_hashtable) && ret;
		else
		{
			iter->u.instruction.offset = offset;
			offset += instruction_size(&iter->u.instruction);
		}
		iter = iter->next;
	}
	*prog_size = offset;
	return (check_instructions_semantics(ast, labels_hashtable, ret));
}
