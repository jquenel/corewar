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
# include "ft_printf.h"
# include "corewar.h"

# define FONT_PATH	"obj/font/Alef-Regular.ttf"

typedef struct	s_2d_coord
{
	int		x;
	int		y;
}				t_2d_coord;

typedef struct 		s_tileset
{
	SDL_Rect		*sprite_list;
	SDL_Surface		*image;
	SDL_Texture		*texture;
	int				nb_tile_x;
	int				nb_tile_y;
	t_2d_coord		*size;
}					t_tileset;

typedef struct	s_state
{
	SDL_Event	event;
	int			state;
	int			frame;
	int			frame_state;
	int			direction;
}				t_state;

typedef struct	s_core
{
	char		*field;
	char		*index;
	int			*pc;
	int			len;
	t_2d_coord	*size;
	int			text_size;
	int			space;
	t_2d_coord	*start;
}				t_core;

void			draw_image(char *path, t_2d_coord *coord, t_2d_coord *size, double angle);
void			draw_SDLSurface(SDL_Surface *bmp, t_2d_coord *coord, t_2d_coord *size, double angle);

SDL_Color 		create_color(int r, int g, int b, int a);
SDL_Color		get_color(char *color_type);
void 			draw_rectangle(t_2d_coord *coord, t_2d_coord *size, char *color_type);
void			draw_tiled_square(t_tileset *tile, t_2d_coord *coord, t_2d_coord *size, int size_unit);

int				draw_text(char *text, int size, t_2d_coord *coord, char *color_type, char *typo);
int				draw_centred_text(char *text, int size, t_2d_coord *coord, char *color_type, char *typo);

void			window_initialisation(char *window_name);
SDL_Renderer	*get_renderer();
t_2d_coord		*get_window_size();
t_2d_coord		*get_mouse_coord();
void			close_renderer();
void			error_exit(char *msg, int error);
void			check_frame();
void			render_screen();

char 			*get_line(int *myfile);
char			**get_strsplit(int *myfile, const char c, int size);

t_2d_coord		*t_2d_coord_new(int x, int y);
void			t_2d_coord_free(t_2d_coord *coord);
void			t_2d_coord_actualize(t_2d_coord *coord, int new_x, int new_y);

t_tileset		*create_tileset(char *path);
t_tileset		*initiate_tileset(char *path, int value_x, int value_y);
void			draw_tileset(t_tileset *tile, int sprite, t_2d_coord *coord, t_2d_coord *size, double angle);

void 			update_input(t_state *state);

int				get_root(int size);
char			*ft_itoa_base(int value, int base);

#endif