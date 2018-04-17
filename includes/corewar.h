/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:46:58 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/21 23:27:07 by sboilard         ###   ########.fr       */
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

#endif
