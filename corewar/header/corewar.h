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

void corewar_live(t_bushi *player);
void corewar_ld(void *value, void *dest);
void corewar_st(void *source, void *dest);
void corewar_add(void *source1, void *source2, void *dest);
void corewar_sub(void *source1, void *source2, void *dest);
void corewar_and(void *source1, void *source2, void *dest);
void corewar_or(void *source1, void *source2, void *dest);
void corewar_xor(void *source1, void *source2, void *dest);
void corewar_zjump(void *dest);
void corewar_ldi(void *source1, void *source2, void *dest);
void corewar_sti(void *source1, void *source2, void *dest);
void corewar_fork(void *dest);
void corewar_lld(void *value, void *dest);
void corewar_lldi(void *source1, void *source2, void *dest);
void corewar_lfork(void *dest);
void corewar_aff(char c);

#endif
