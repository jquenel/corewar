/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2017/11/25 00:41:35 by jboissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_H
# define TEMPLATE_H

# include <unistd.h>
# include <fcntl.h>
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>

# include "libft.h"
# include "corewar.h"
# include "ft_printf.h"

# define FONT_PATH		"font/KeepCalm-Medium.ttf"

# define NB_COLOR		20

# define BLACK			0
# define WHITE			1
# define LIGHT_BLUE		2
# define BLUE			3
# define DARK_BLUE		4
# define LIGHT_RED		5
# define RED			6
# define DARK_RED		7
# define LIGHT_GREEN	8
# define GREEN			9
# define DARK_GREEN		10
# define LIGHT_CYAN		11
# define CYAN			12
# define DARK_CYAN		13
# define LIGHT_GREY		14
# define GREY			15
# define DARK_GREY		16
# define LIGHT_ORANGE	17
# define ORANGE			18
# define DARK_ORANGE	19

# define P1_COLOR		BLUE
# define P2_COLOR		RED
# define P3_COLOR		GREEN
# define P4_COLOR		CYAN


typedef struct	s_vect
{
	int		x;
	int		y;
}				t_vect;

typedef struct 		s_tileset
{
	SDL_Rect		*sprite_list;
	SDL_Surface		*image;
	SDL_Texture		*texture;
	int				nb_tile_x;
	int				nb_tile_y;
	t_vect			*size;
}					t_tileset;

typedef struct	s_visu
{
	int			*corewar_opt;
	char		*field;
	char		*index;
	int			len;
	TTF_Font 	*font;
	TTF_Font 	*menu_font;
	int			p_color[5];
	SDL_Texture *texture_list[256];
	int			font_size;
	t_vect	*tab_size;
	t_vect	*base_pos;
	double		zoom;
	int			unit;
	int			space;
}				t_visu;

void			draw_image(char *path, t_vect *coord, t_vect *size, double angle);
void			draw_SDLSurface(SDL_Surface *bmp, t_vect *coord, t_vect *size, double angle);
void 			draw_SDLTexture(SDL_Texture *texture, t_vect *coord, t_vect *size, double angle);
void 			draw_centred_SDLTexture(SDL_Texture *texture, t_vect *coord, double angle);

SDL_Color 		create_color(int r, int g, int b, int a);
SDL_Color		get_color(int i);
void 			draw_rectangle(t_vect *coord, t_vect *size, int color_type);
void 			draw_border_rectangle(t_vect *coord, t_vect *size, int color_type);
void			draw_tiled_square(t_tileset *tile, t_vect *coord, t_vect *size, int size_unit);

int				draw_text(char *text, t_vect *coord, int color_type, TTF_Font *font, char *typo);
int				draw_centred_text(char *text, t_vect *coord, int color_type, TTF_Font *font, char *typo);

void			window_initialisation(char *window_name);
SDL_Renderer	*get_renderer();
t_vect			*get_win_size();
void			close_renderer();
void			error_exit(char *msg, int error);
void			check_frame();
void			render_screen();

char 			*get_line(int *myfile);
char			**get_strsplit(int *myfile, const char c, int size);

t_vect			*t_vect_new(int x, int y);
void			t_vect_free(t_vect *coord);
void			t_vect_actualize(t_vect *coord, int new_x, int new_y);

t_tileset		*create_tileset(char *path);
t_tileset		*initiate_tileset(char *path, int value_x, int value_y);
void			draw_tileset(t_tileset *tile, int sprite, t_vect *coord, t_vect *size, double angle);

void 			update_input(t_visu *core);

int				get_root(int size);
char			*ft_itoa_base(int value, char *base);
void			ft_stradd_front(char *s1, char **s2);
void			ft_stradd_back(char **s1, char *s2);

t_visu			*create_t_visu(t_sen *core);
void 			draw_core(t_visu *core);
void			draw_pc(t_sen *core, t_visu *sdl_core);
void			draw_menu(t_sen *core, t_visu *sdl_core, int cycles);
void 			set_texture_list(t_visu *core);

#endif
