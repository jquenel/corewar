/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:46:58 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/17 19:31:46 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"

typedef struct			s_ban
{
	int					size;
	char				field[MEM_SIZE];
}						t_ban;

typedef struct			s_bushi
{
	int					pnum;
	int					carry;
	int					live;
	int					reg[REG_NUMBER + 1];
	char				name[PROG_NAME_LENGTH + 1];
}						t_bushi;

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
	t_sumego			state;
	t_bushi				player[MAX_PLAYERS];
	t_ban				arena;
}						t_sen;

/*
**		t_arg
**		type : type de la valeur (1 = registre, 2 = Direct value, 3 = Indirect value)
**
*/
typedef struct			s_arg
{
	char				type;
	char				size
	char				data[MAX_ARG_SIZE];
}						t_arg;

int	parser(int argc, char **argv);
int	get_options(int argc, char **argv, t_sen *core);
int	load_player(int i, int argc, char **argv, t_sen *core);
int	is_all_nums(char *s);

void	corewar_live(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_ld(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_st(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_add(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_sub(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_and(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_or(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_xor(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_zjump(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_ldi(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_sti(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_fork(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_lld(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_lldi(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_lfork(t_sen *arena, t_bushi *actual, t_arg *arg_list);
void	corewar_aff(t_sen *arena, t_bushi *actual, t_arg *arg_list);

#endif
