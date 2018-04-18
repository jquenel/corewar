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
	char				*field;
}						t_ban;

typedef struct			s_bushi
{
	int					pnum;
	int					carry;
	int					live;
	int					reg[REG_NUMBER + 1];
	char				*name;
	struct s_bushi		*next;
}						t_bushi;

typedef struct			s_sumego
{
	int					c_count;
	int					c_total;
	int					c_todie;
	int					c_delta;
	int					c_limit;
	int					l_count;
	int					l_limit;
	int					dump_limit;
}						t_sumego;

typedef struct			s_sen
{
	int					opt;
	t_sumego			*state;
	t_bushi				*player;
	t_ban				*arena;
}						t_sen;

/*
**		t_arg
**		type : type de la valeur (1 = registre, 2 = Direct value, 3 = Indirect value)
**
*/
typedef struct			s_arg
{
	char				type;
	void				*adress;
	char				size
}						t_arg;

void corewar_live(t_sen *arena, t_arg *arg_list);
void corewar_ld(t_sen *arena, t_arg *arg_list);
void corewar_st(t_sen *arena, t_arg *arg_list);
void corewar_add(t_sen *arena, t_arg *arg_list);
void corewar_sub(t_sen *arena, t_arg *arg_list);
void corewar_and(t_sen *arena, t_arg *arg_list);
void corewar_or(t_sen *arena, t_arg *arg_list);
void corewar_xor(t_sen *arena, t_arg *arg_list);
void corewar_zjump(t_sen *arena, t_arg *arg_list);
void corewar_ldi(t_sen *arena, t_arg *arg_list);
void corewar_sti(t_sen *arena, t_arg *arg_list);
void corewar_fork(t_sen *arena, t_arg *arg_list);
void corewar_lld(t_sen *arena, t_arg *arg_list);
void corewar_lldi(t_sen *arena, t_arg *arg_list);
void corewar_lfork(t_sen *arena, t_arg *arg_list);
void corewar_aff(t_sen *arena, t_arg *arg_list);

#endif