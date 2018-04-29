/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:46:58 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:20:47 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"
# include "ft_printf.h"
#include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE		512
# endif

# define FIELD			core->arena.field
# define TRACE_EMPTY	-1

typedef struct			s_ban
{
	int					size;
	char				field[MEM_SIZE];
	char				empty_char;
	char				trace[MEM_SIZE];
}						t_ban;

/*
**		The players are stored in the t_bushi structures, allocated as a tab.
**		live <= -2 : not a player in this game
**		live == -1 : dead
**		live == 0 alive
**		live == 1 alive this cycle
*/

typedef struct			s_bushi
{
	int					pnum;
	int					live;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
}						t_bushi;

typedef struct			s_arg
{
	char				type;
	char				size;
	char				data[MAX_ARG_SIZE];
}						t_arg;

typedef struct			s_bo
{
	int					pnum;
	int					carry;
	int					pc;
	int					live;
	struct s_optab		*op;
	int					cycle;
	int					size;
	t_arg				args[MAX_ARGS_NUMBER];
	char				reg[REG_NUMBER][REG_SIZE];
	struct s_bo				*next;
}						t_bo;

typedef struct			s_sumego
{
	int					c_count;
	int					c_total;
	int					c_todie;
	int					c_delta;
	int					l_count;
	int					l_checks;
	int					l_checks_limit;
	int					l_limit;
	int					dump_limit;
}						t_sumego;

typedef struct			s_visu
{
	int					pause;
}						t_visu;

typedef struct			s_sen
{
	int					opt;
	int					pcount;
	t_sumego			state;
	t_ban				arena;
	t_visu				visu;
	t_bo				*proc;
	t_bushi				player[MAX_PLAYERS + 1];
}						t_sen;

/*
**		The extra char is holding extra infomations :
**			change in IND_SIZE (EX_IS)
**			presence of an encoding byte (EX_CD)
*/

# define OP_COUNT		16
# define EX_CD			1
# define EX_IS			2

typedef struct			s_optab
{
	int					(*op)(t_sen *core, t_bo *actual, t_arg *args);
	int					arg_count;
	arg_type_t			arg_types[MAX_ARGS_NUMBER];
	int					cycle;
	char				extra;
}						t_optab;

int		parser(int argc, char **argv, t_sen *core);
int		get_options(int *argc, char ***argv, t_sen *core);
int		count_players(int argc, char **argv);
int		create_player(int *argc, char ***argv, t_sen *core, int i);
int		load_program(char *file, t_ban *arena, t_bushi *player, t_bo *proc);
int		is_all_nums(char *s);
void	start_battle(t_sen *core);
void	init_optab(t_optab op[OP_COUNT + 1]);
void	cycle(t_sen *core, t_optab op[OP_COUNT + 1]);
int		fast_cycle(t_sen *core, t_optab op[OP_COUNT + 1]);
void	do_op(t_sen *core, t_bo *actual);
int		plan_op(t_sen *core, t_bo *actual, t_optab op[OP_COUNT + 1]);

void	dump_core(t_sen *core);
int		destroy_processes(t_bo *proc);


int		corewar_live(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_ld(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_st(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_add(t_sen *core, t_bo *actual, t_arg *args);
int		corewar_sub(t_sen *core, t_bo *actual, t_arg *args);
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

void	copy_data(t_sen *core, char *dest, int pc, int size);
int		dtoi(char *data, int size);
int		core_getvalue(t_sen *core, t_arg *arg, int pc);
int		core_getlvalue(t_sen *core, t_arg *arg, int pc);
void	core_regtomem(t_ban *arena, char *src, int dest, int pnum);
void	malloc_error(t_sen *core);

#endif
