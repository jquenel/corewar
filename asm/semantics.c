/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:58:27 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/21 16:35:14 by sboilard         ###   ########.fr       */
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

static int	record_label(const t_label_element *elem, size_t offset,
						t_hashtable *labels_hashtable)
{
	t_label_value	*label;

	if (ft_hashtable_find(labels_hashtable, &elem->name) != NULL)
	{
		ft_dprintf(STDERR_FILENO, "Duplicate label \"%s\".\n", elem->name);
		return (0);
	}
	label = (t_label_value *)xmalloc(sizeof(*label));
	label->str = elem->name;
	label->offset = offset;
	if (!ft_hashtable_insert(labels_hashtable, label))
		die_oom();
	return (1);
}

static int	check_operand(const t_operand_list *oper, size_t id, const t_op *op,
							t_hashtable *labels_hashtable)
{
	int	ret;

	ret = 1;
	if ((oper->type == RegisterOper && !(op->arg_types[id] & T_REG))
		|| (oper->type != RegisterOper
			&& ((oper->direct_flag && !(op->arg_types[id] & T_DIR))
				|| (!oper->direct_flag && !(op->arg_types[id] & T_IND)))))
	{
		ft_dprintf(
			STDERR_FILENO,
			"Operand #%u \"%s\" has illegal type for operator \"%s\".\n",
			id + 1, oper->str, op->mnemo);
		ret = 0;
	}
	if (oper->type == LabelOper
		&& ft_hashtable_find(labels_hashtable, &oper->str) == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Unknown label \"%s\".\n", oper->str);
		ret = 0;
	}
	return (ret);
}

static int	check_instruction_semantics(const t_operand_list *operands,
										t_hashtable *labels_hashtable,
										const t_op *op)
{
	const t_operand_list	*iter;
	unsigned int			i;
	int						ret;

	iter = operands;
	i = 0;
	ret = 1;
	while (i < op->nbr_arg && iter != NULL)
	{
		ret = check_operand(iter, i, op, labels_hashtable) && ret;
		++i;
		iter = iter->next;
	}
	if (i < op->nbr_arg || iter != NULL)
	{
		ft_dprintf(STDERR_FILENO, "Operator \"%s\" expects %u arguments.\n",
					op->mnemo, op->nbr_arg);
		return (0);
	}
	return (ret);
}

static int	check_instructions_semantics(t_ast *ast,
										t_hashtable *labels_hashtable)
{
	int				ret;
	t_element_list	*iter;
	const char		*mnemo;
	const t_op		*op;

	ret = 1;
	iter = ast->elements;
	while (iter != NULL)
	{
		if (iter->type == InstructionElem)
		{
			mnemo = iter->u.instruction.operator;
			op = g_op_tab + mnemo_id(mnemo);
			if (op == g_op_tab - 1)
			{
				ft_dprintf(STDERR_FILENO, "Unknown operator \"%s\".\n", mnemo);
				ret = 0;
			}
			else
				ret = check_instruction_semantics(
					iter->u.instruction.operands, labels_hashtable, op) && ret;
		}
		iter = iter->next;
	}
	return (ret);
}

int			check_semantics(t_ast *ast, t_hashtable **labels_hashtable,
							size_t *prog_size)
{
	int				ret;
	t_element_list	*iter;
	size_t			offset;

	ret = 1;
	iter = ast->elements;
	*labels_hashtable =
		ft_hashtable_make(ft_hashfun_string, ft_compfun_string, 8);
	if (labels_hashtable == NULL)
		die_oom();
	offset = 0;
	while (iter != NULL)
	{
		if (iter->type == LabelElem)
			ret = record_label(&iter->u.label, offset, *labels_hashtable)
				&& ret;
		else
		{
			iter->u.instruction.offset = offset;
			offset += instruction_size(&iter->u.instruction);
		}
		iter = iter->next;
	}
	*prog_size = offset;
	return (ret && check_instructions_semantics(ast, *labels_hashtable));
}
