/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:46:58 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/21 23:28:54 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"
//# include "ft_printf.h"
#include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE		512
# endif

typedef struct			s_ban
{
	int					size;
	char				field[MEM_SIZE];
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

typedef struct			s_bo
{
	int					pnum;
	int					carry;
	int					reg[REG_NUMBER + 1];
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
	int					l_limit;
	int					dump_limit;
}						t_sumego;

typedef struct			s_sen
{
	int					opt;
	int					pcount;
	t_sumego			state;
	t_ban				arena;
	t_bo				*proc;
	t_bushi				player[MAX_PLAYERS + 1];
}						t_sen;

/*
**		t_arg
**		type : type de la valeur (1 = registre, 2 = Direct value, 3 = Indirect value)
**
*/
typedef struct			s_arg
{
	char				type;
	char				size;
	char				data[MAX_ARG_SIZE];
}						t_arg;

int	parser(int argc, char **argv, t_sen *core);
int	get_options(int *argc, char ***argv, t_sen *core);
int	count_players(int argc, char **argv);
int	create_player(int *argc, char ***argv, t_sen *core, int i);
int	load_program(char *file, t_ban *arena, t_bushi *player, t_bo *proc);
int	is_all_nums(char *s);

void	dump_core(t_sen *core);
int		destroy_processes(t_bo *proc);

int	corewar_live(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_ld(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_st(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_add(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_sub(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_and(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_or(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_xor(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_zjump(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_ldi(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_sti(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_fork(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_lld(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_lldi(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_lfork(t_sen *arena, t_bo *actual, t_arg *arg_list);
int	corewar_aff(t_sen *arena, t_bo *actual, t_arg *arg_list);

#endif
