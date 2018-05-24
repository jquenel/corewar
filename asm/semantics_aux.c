/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantics_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:58:37 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 19:48:52 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft_hashtable.h>
#include <libft_std.h>
#include <unistd.h>
#include "ast.h"
#include "op.h"
#include "semantics.h"

int	check_operand_type(const t_element_list *elem, unsigned int id,
						const t_op *op)
{
	const t_operand_list	*oper;

	oper = (const t_operand_list *)
		*ft_list_at((t_list **)&elem->u.instruction.operands, id);
	if ((oper->type == RegisterOper && !(op->arg_types[id] & T_REG))
		|| (oper->type != RegisterOper
			&& ((oper->direct_flag && !(op->arg_types[id] & T_DIR))
				|| (!oper->direct_flag && !(op->arg_types[id] & T_IND)))))
	{
		ft_dprintf(
			STDERR_FILENO, "Operand #%u \"%s\" at line %u has illegal type for "
			"operator \"%s\".\n", id + 1, oper->str, elem->line_nbr, op->mnemo);
		return (0);
	}
	return (1);
}

int	check_label_exists(const t_element_list *elem, unsigned int id,
						t_hashtable *labels_hashtable, int ret)
{
	const t_operand_list	*oper;

	oper = (const t_operand_list *)
		*ft_list_at((t_list **)&elem->u.instruction.operands, id);
	if (ft_hashtable_find(labels_hashtable, &oper->str) == NULL)
	{
		ft_dprintf(
			STDERR_FILENO, "Unknown label \"%s\" at line %u in operand #%u.\n",
			oper->str, elem->line_nbr, id);
		return (0);
	}
	return (ret);
}

int	check_register_number(const t_element_list *elem, unsigned int id, int ret)
{
	const t_operand_list	*oper;
	int						n;

	oper = (const t_operand_list *)
		*ft_list_at((t_list **)&elem->u.instruction.operands, id);
	ft_int_of_string(oper->str + 1, &n);
	if (n < 0 || n >= REG_NUMBER)
	{
		ft_dprintf(
			STDERR_FILENO, "Invalid register \"%s\" at line %u in operand #%u.\n",
			oper->str, elem->line_nbr, id);
		return (0);
	}
	return (ret);
}
