/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 18:46:28 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/25 17:44:41 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_STRUCT_H
# define COREWAR_STRUCT_H

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>

# define OP_COUNT		16
# define BONUS_OP_COUNT	20
# define MAX_VIC_LEN	1024

typedef struct			s_ban
{
	int					size;
	char				*field;
	char				empty_char;
	char				*trace;
}						t_ban;

/*
**		The players are stored in the t_bushi structures, allocated as a tab.
**		live <= -2 : not a player in this game
**		live == -1 : dead
**		live == 0 alive
**		live >= 1 alive this cycle
*/

typedef struct			s_bushi
{
	int					pnum;
	int					pindex;
	int					weight;
	int					live;
	int					live_last;
	int					proc_count;
	int					vic_ccount;
	char				vic_shout[MAX_VIC_LEN + 1];
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	char				*txt_pnum;
}						t_bushi;

typedef struct			s_arg
{
	char				type;
	char				size;
	char				data[MAX_ARG_SIZE];
}						t_arg;

typedef struct			s_bo
{
	t_bushi				*parent;
	int					carry;
	int					pc;
	int					live;
	struct s_optab		*op;
	int					cycle;
	int					size;
	t_arg				args[MAX_ARGS_NUMBER];
	char				reg[REG_NUMBER][REG_SIZE];
	struct s_bo			*next;
	struct s_bo			*prev;
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
	int					l_last;
	int					dump_limit;
}						t_sumego;

typedef struct			s_sen
{
	int					opt;
	int					pcount;
	t_sumego			state;
	t_ban				arena;
	struct s_optab		*op;
	t_bo				*proc;
	struct s_visu		*visu;
	t_bushi				player[MAX_PLAYERS + 1];
}						t_sen;

/*
**		The extra char is holding extra infomations :
**			change in IND_SIZE (EX_IS)
**			presence of an encoding byte (EX_CD)
*/

# define EX_CD			1
# define EX_IS			2

typedef struct			s_optab
{
	int					(*op)(t_sen *core, t_bo *actual, t_arg *args);
	int					arg_count;
	t_arg_type			arg_types[MAX_ARGS_NUMBER];
	int					cycle;
	char				extra;
}						t_optab;

/*
**		Visu also has its own structs
*/

typedef struct			s_vect
{
	int					x;
	int					y;
}						t_vect;

typedef struct			s_visu
{
	int					*corewar_opt;
	char				*field;
	char				*index;
	int					len;
	TTF_Font			*font;
	TTF_Font			*final_font;
	TTF_Font			*menu_font;
	int					p_color[5];
	SDL_Texture			*texture_list[256];
	SDL_Texture			*texture_menu_list[256];
	int					typo_tab[5];
	char				*str_list[OP_COUNT + 1];
	int					font_size;
	int					menu_font_size;
	int					final_font_size;
	t_vect				*tab_size;
	t_vect				*base_pos;
	double				zoom;
	int					unit_pc;
	int					unit;
	int					space;
	char				pause;
	char				help;
	char				one_cycle;
	float				cycle_to_jump;
	Mix_Music			*music;
	Mix_Chunk			*birth_sound;
	Mix_Chunk			*end_sound;
	t_bo				*select_proc;
}						t_visu;

typedef struct			s_typo
{
	int					color_type;
	TTF_Font			*font;
	int					typo;
}						t_typo;

#endif
