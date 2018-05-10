/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:58:27 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/10 00:56:58 by sboilard         ###   ########.fr       */
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

static int	check_instruction_semantics(const t_instruction_element *elem,
										t_hashtable *labels_hashtable)
{
	const t_op				*op;
	unsigned int			i;
	int						ret;
	const t_operand_list	*iter;

	op = g_op_tab + mnemo_id(elem->operator);
	if (op == g_op_tab - 1)
	{
		ft_dprintf(STDERR_FILENO, "Unknown operator \"%s\".\n", elem->operator);
		return (0);
	}
	i = 0;
	ret = 1;
	iter = elem->operands;
	while (i < op->nbr_arg && iter != NULL)
	{
		if ((iter->type == RegisterOper && !(op->arg_types[i] & T_REG))
			|| (iter->type != RegisterOper
				&& ((iter->direct_flag && !(op->arg_types[i] & T_DIR))
					|| (!iter->direct_flag && !(op->arg_types[i] & T_IND)))))
		{
			ft_dprintf(STDERR_FILENO,
						"Operand #%u \"%s\" has illegal type for operator \"%s\".\n",
						i + 1, iter->str, op->mnemo);
			ret = 0;
		}
		if (iter->type == LabelOper && ft_hashtable_find(labels_hashtable, &iter->str) == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Unknown label \"%s\".\n", iter->str);
			ret = 0;
		}
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

int			check_semantics(t_ast *ast, t_hashtable **labels_hashtable, size_t *prog_size)
{
	int				ret;
	t_element_list	*iter;
	size_t			offset;

	ret = 1;
	iter = ast->elements;
	*labels_hashtable = ft_hashtable_make(ft_hashfun_string, ft_compfun_string, 8);
	if (labels_hashtable == NULL)
		die_oom();
	offset = 0;
	while (iter != NULL)
	{
		if (iter->type == LabelElem)
			ret = record_label(&iter->u.label, offset, *labels_hashtable) && ret;
		else
		{
			iter->u.instruction.offset = offset;
			offset += instruction_size(&iter->u.instruction);
		}
		iter = iter->next;
	}
	*prog_size = offset;
	iter = ast->elements;
	while (iter != NULL)
	{
		if (iter->type == InstructionElem)
			ret = check_instruction_semantics(&iter->u.instruction, *labels_hashtable) && ret;
		iter = iter->next;
	}
	return (ret);
}
