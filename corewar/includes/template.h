/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/07 15:47:30 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_H
# define TEMPLATE_H

# include <unistd.h>
# include <fcntl.h>
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>

# include "libft.h"
# include "corewar.h"
# include "ft_printf.h"

# define FONT_PATH		"font/KeepCalm-Medium.ttf"
# define MUSIC_PATH		"audio/bensound-instinct.wav"
# define END_SOUND		"audio/end_turn.wav"

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

void			draw_image(char *path, t_vect *coord, t_vect *size, double angle);
void			draw_sdlsurface(SDL_Surface *bmp, t_vect *coord, t_vect *size, double angle);
void 			draw_sdltexture(SDL_Texture *texture, t_vect *coord, t_vect *size, double angle);
void 			draw_centred_sdltexture(SDL_Texture *texture, t_vect *coord, double angle);

SDL_Color 		create_color(int r, int g, int b, int a);
SDL_Color		get_color(int i);
void 			draw_rectangle(t_vect *coord, t_vect *size, int color_type);
void 			draw_border_rectangle(t_vect *coord, t_vect *size, int color_type);

int				draw_text(char *text, t_vect *coord, t_typo *v_typo);
int				draw_centred_text(char *text, t_vect *coord, t_typo *v_typo);

void			window_initialisation(char *window_name);
void			set_fps(int i);
void			reset_fps(int i);
int				get_fps();
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

void 			update_input(t_visu *core);

int				get_root(int size);
char			*ft_itoa_base(int value, char *base);
char			*ft_strnew(size_t size);
void			ft_stradd_front(char *s1, char **s2);
void			ft_stradd_back(char **s1, char *s2);

t_visu			*create_t_visu(t_sen *core);
void 			draw_core(t_visu *core);
void			draw_pc(t_sen *core, t_visu *sdl_core);
void			draw_menu(t_sen *core, t_visu *sdl_core);
void			draw_info(t_sen *core, t_visu *visu);
void			draw_selected(t_sen *core, t_visu *visu);
void 			set_texture_list(t_visu *core);

void			reset_visu(t_visu *visu);

void			set_color_tab(void);

char			*poor_itoa(int nbr, char *buffer);

t_typo			*set_t_typo(t_typo *v_font, char *typo, int color_type,
																TTF_Font *font);

void			destroy_t_visu(t_visu *visu);

#endif
