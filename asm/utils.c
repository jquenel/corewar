/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 00:09:31 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/10 00:57:22 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>
#include <stddef.h>
#include "ast.h"
#include "op.h"
#include "utils.h"
#include "xmalloc.h"

char	*get_output_filename(const char *filename)
{
	size_t	len;
	char	*new_filename;

	len = ft_strlen(filename);
	if (len >= 2 && filename[len - 1] == 's' && filename[len - 2] == '.')
		len -= 2;
	new_filename = (char *)xmalloc(len + 5);
	ft_strncpy(new_filename, filename, len);
	new_filename[len] = '.';
	new_filename[len + 1] = 'c';
	new_filename[len + 2] = 'o';
	new_filename[len + 3] = 'r';
	new_filename[len + 4] = '\0';
	return (new_filename);
}

size_t	instruction_size(const t_instruction_element *elem)
{
	const t_op				*op;
	size_t					size;
	const t_operand_list	*iter;

	if ((op = g_op_tab + mnemo_id(elem->operator)) == g_op_tab - 1)
		return (1);
	size = 1 + op->code_size;
	iter = elem->operands;
	while (iter != NULL)
	{
		if (iter->type == RegisterOper)
			++size;
		else if (!iter->direct_flag || op->short_enc)
			size += IND_SIZE;
		else
			size += DIR_SIZE;
		iter = iter->next;
	}
	return (size);
}

int		mnemo_id(const char *mnemo)
{
	int	i;

	i = 0;
	while (g_op_tab[i].mnemo != NULL)
	{
		if (ft_strcmp(g_op_tab[i].mnemo, mnemo) == 0)
			return (i);
		++i;
	}
	return (-1);
}
