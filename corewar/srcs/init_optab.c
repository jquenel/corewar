/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_optab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:19:26 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/24 19:04:22 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	(*g_operation[BONUS_OP_COUNT + 1])(t_sen *, t_bo *, t_arg *) =
{
	corewar_live,
	corewar_ld,
	corewar_st,
	corewar_add,
	corewar_sub,
	corewar_and,
	corewar_or,
	corewar_xor,
	corewar_zjmp,
	corewar_ldi,
	corewar_sti,
	corewar_fork,
	corewar_lld,
	corewar_lldi,
	corewar_lfork,
	corewar_aff,
	corewar_mul,
	corewar_div,
	corewar_not,
	corewar_vic,
	NULL
};

void		init_optab(t_sen *core, t_visu *visu, t_optab **op)
{
	int		i;
	int		j;

	i = (core->opt & OPT_INST) ? BONUS_OP_COUNT : OP_COUNT;
	if (!(*op = malloc(sizeof(t_optab) * (i + 1))))
		malloc_error(core, visu);
	while (i--)
	{
		(*op)[i].arg_count = g_op_tab[i].nbr_arg;
		(*op)[i].cycle = g_op_tab[i].cycles;
		j = MAX_ARGS_NUMBER;
		while (j--)
			(*op)[i].arg_types[j] = g_op_tab[i].arg_types[j];
		(*op)[i].op = g_operation[i];
		(*op)[i].extra = 0;
		(*op)[i].extra |= g_op_tab[i].code_size ? EX_CD : 0;
		(*op)[i].extra |= g_op_tab[i].short_enc ? EX_IS : 0;
	}
}
