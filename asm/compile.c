/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:02:59 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 14:14:25 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ft_printf.h>
#include <libft_hashtable.h>
#include <libft_std.h>
#include <libft_str.h>
#include <stdlib.h>
#include <unistd.h>
#include "ast.h"
#include "compile.h"
#include "op.h"
#include "semantics.h"
#include "utils.h"

static int	code_byte(const t_operand_list *oper)
{
	unsigned char	c;
	size_t			shift;

	c = 0;
	shift = 6;
	while (oper != NULL)
	{
		if (oper->type == RegisterOper)
			c |= REG_CODE << shift;
		else
			c |= (oper->direct_flag ? DIR_CODE : IND_CODE) << shift;
		oper = oper->next;
		shift -= 2;
	}
	return (c);
}

static void	emit_operand(t_core *core, uint32_t l, int short_enc,
						const t_operand_list *oper)
{
	uint16_t	s;

	if (!oper->direct_flag || short_enc)
	{
		s = ft_htons(l);
		ft_memcpy(core->core + core->offset, &s, IND_SIZE);
		core->offset += IND_SIZE;
	}
	else
	{
		l = ft_htonl(l);
		ft_memcpy(core->core + core->offset, &l, DIR_SIZE);
		core->offset += DIR_SIZE;
	}
}

static void	emit_operands(const t_instruction_element *instr,
							t_hashtable *labels, t_core *core, int short_enc)
{
	uint32_t				l;
	uint8_t					c;
	int						tmp;
	const t_operand_list	*oper;

	oper = instr->operands;
	while (oper != NULL)
	{
		if (oper->type == RegisterOper)
		{
			ft_int_of_string(oper->str + 1, &tmp);
			c = tmp;
			core->core[core->offset++] = c;
		}
		else
		{
			l = (oper->type == LabelOper)
				? ((t_label_value *)ft_hashtable_find(
					labels, &oper->str))->offset - instr->offset
				: ft_atoi(oper->str);
			emit_operand(core, l, short_enc, oper);
		}
		oper = oper->next;
	}
}

static void	emit_code(t_ast *ast, t_hashtable *labels, t_core *core)
{
	t_element_list	*iter;
	const t_op		*op;
	uint8_t			c;

	iter = ast->elements;
	while (iter != NULL)
	{
		if (iter->type == InstructionElem)
		{
			op = g_op_tab + mnemo_id(iter->u.instruction.operator);
			c = op->index;
			core->core[core->offset++] = c;
			if (op->code_size)
			{
				c = code_byte(iter->u.instruction.operands);
				core->core[core->offset++] = c;
			}
			emit_operands(&iter->u.instruction, labels, core, op->short_enc);
		}
		iter = iter->next;
	}
}

int			compile(t_ast *ast, t_hashtable *labels, const char *filename,
					size_t prog_size)
{
	char	*output_filename;
	int		output_fd;
	t_core	*core;
	int		ret;

	output_filename = get_output_filename(filename);
	output_fd = open(output_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	free(output_filename);
	if (output_fd < 0)
	{
		ft_dprintf(STDERR_FILENO, "Could not open output file.\n");
		return (0);
	}
	core = make_core(ast, prog_size);
	emit_code(ast, labels, core);
	ret = write(output_fd, &core->header, sizeof(core->header) + prog_size);
	close(output_fd);
	if (ret < 0)
	{
		ft_dprintf(STDERR_FILENO, "I/O error writing output file.\n");
		return (0);
	}
	return (1);
}
