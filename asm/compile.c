/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:02:59 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/10 00:56:44 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
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

static void	emit_operands(const t_instruction_element *instr,
							t_hashtable *labels, int fd, int short_enc)
{
	uint32_t				l;
	uint16_t				s;
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
			write(fd, &c, 1);
		}
		else
		{
			if (oper->type == LabelOper)
				l = ((t_label_value *)ft_hashtable_find(labels, &oper->str))->offset - instr->offset;
			else
				l = ft_atoi(oper->str);
			if (!oper->direct_flag || short_enc)
			{
				s = ft_htons(l);
				write(fd, &s, IND_SIZE);
			}
			else
			{
				l = ft_htonl(l);
				write(fd, &l, DIR_SIZE);
			}
		}
		oper = oper->next;
	}
}

static void	emit_code(t_ast *ast, t_hashtable *labels, int fd)
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
			write(fd, &c, 1);
			if (op->code_size)
			{
				c = code_byte(iter->u.instruction.operands);
				write(fd, &c, 1);
			}
			emit_operands(&iter->u.instruction, labels, fd, op->short_enc);
		}
		iter = iter->next;
	}
}

int			compile(t_ast *ast, t_hashtable *labels, const char *filename,
					size_t prog_size)
{
	char			*output_filename;
	int				output_fd;
	t_header		header;

	output_filename = get_output_filename(filename);
	output_fd = open(output_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	free(output_filename);
	if (output_fd < 0)
		return (0);
	header.magic = COREWAR_EXEC_MAGIC;
	ft_strncpy(header.prog_name, ast->name, PROG_NAME_LENGTH);
	header.null1 = 0;
	header.prog_size = ft_htonl(prog_size);
	ft_strncpy(header.comment, ast->comment, COMMENT_LENGTH);
	header.null2 = 0;
	write(output_fd, &header, sizeof(header));
	emit_code(ast, labels, output_fd);
	close(output_fd);
	return (1);
}
