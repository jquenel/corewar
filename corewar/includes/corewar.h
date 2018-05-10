/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:46:58 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/10 22:13:01 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"
# include "ft_printf.h"
# include "corewar_struct.h"

#include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE		512
# endif

# ifndef INT_MAX
#  define INT_MAX		2147483647
# endif

# define FIELD			core->arena.field
# define TRACE_EMPTY	0

# define OPT_DUMP		(1 << ('d' - 'a'))
# define OPT_FAST		(1 << ('f' - 'a'))
# define OPT_INST		(1 << ('i' - 'a'))
# define OPT_DETH		(1 << ('s' - 'a'))
# define OPT_VISU		(1 << ('v' - 'a'))
# define OPT_VERB		(1 << ('w' - 'a'))

int		parser(int argc, char **argv, t_sen *core);
int		get_options(int *argc, char ***argv, t_sen *core);
int		count_players(int argc, char **argv);
int		create_player(int *argc, char ***argv, t_sen *core, int i);
int		load_program(char *file, t_ban *arena, t_bushi *player, t_bo *proc);
int		is_all_nums(char *s);
void	start_battle(t_sen *core);
void	init_optab(t_sen *core, t_visu *visu, t_optab **op);
int		cycle(t_sen *core, t_optab op[OP_COUNT + 1]);
int			fast_cycle(t_sen *core, t_optab op[OP_COUNT + 1]);
void	do_op(t_sen *core, t_bo *actual);
int		plan_op(t_sen *core, t_bo *actual, t_optab op[OP_COUNT + 1]);
int		tsumego(t_sen *core);
void	declare_winner(t_sen *core, t_visu *visu);

void	dump_core(t_sen *core);
int		destroy_processes(t_bo *proc);

int		corewar_live(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_ld(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_st(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_add(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_sub(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_div(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_mul(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_not(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_and(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_or(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_xor(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_zjmp(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_ldi(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_sti(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_fork(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_lld(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_lldi(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_lfork(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_aff(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_vic(t_sen *core, t_bo *actual, t_arg *args);

void	copy_data(t_sen *core, char *dest, int pc, int size);
int		dtoi(char *data, int size);
int		get_regs(t_arg *args, int *is_reg, int i);
int		core_getvalue(t_sen *core, t_arg *arg, t_bo *actual);
int		core_getlvalue(t_sen *core, t_arg *arg, t_bo *actual);
void	core_regtomem(t_ban *arena, char *src, int dest, int pnum);
void	malloc_error(t_sen *core, t_visu *visu);

#endif
