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

#include "template.h"

SDL_Renderer	    *renderer;
SDL_Window		    *window;
t_vect		    	*window_size;
int           		FPS = 60;
SDL_Color			color_tab[NB_COLOR];

void	set_color_tab()
{
	color_tab[BLACK] = create_color(39, 39, 39, 42);
	color_tab[WHITE] = create_color(240, 240, 240, 42);
	color_tab[LIGHT_BLUE] = create_color(135, 206, 250, 42);
	color_tab[BLUE] = create_color(30, 144, 255, 42);
	color_tab[DARK_BLUE] = create_color(0, 0, 139, 42);
	color_tab[LIGHT_RED] = create_color(221, 110, 110, 42);
	color_tab[RED] = create_color(165, 89, 89, 42);
	color_tab[DARK_RED] = create_color(110, 70, 70, 42);
	color_tab[LIGHT_GREEN] = create_color(170, 220, 115, 42);
	color_tab[GREEN] = create_color(89, 165, 89, 42);
	color_tab[DARK_GREEN] = create_color(30, 100, 60, 42);
	color_tab[LIGHT_CYAN] = create_color(127, 255, 212, 42);
	color_tab[CYAN] = create_color(64, 224, 208, 42);
	color_tab[DARK_CYAN] = create_color(0,139,139, 42);
	color_tab[LIGHT_GREY] = create_color(175, 175, 175, 42);
	color_tab[GREY] = create_color(86, 86, 86, 42);
	color_tab[DARK_GREY] = create_color(56, 56, 56, 42);
	color_tab[LIGHT_ORANGE] = create_color(255, 195, 0, 42);
	color_tab[ORANGE] = create_color(255, 165, 0, 42);
	color_tab[DARK_ORANGE] = create_color(255, 130, 0, 42);
}

void		set_fps(int i)
{
	FPS = (FPS + i > 120 ? 120 : (FPS + i < 1 ? 1 : FPS + i));
}

void		reset_fps(int i)
{
	FPS = i;
}

int			get_fps()
{
	return (FPS);
}

SDL_Color get_color(int i)
{
	if (i < 0 || i > NB_COLOR)
		return (color_tab[0]);
	return (color_tab[i]);
}

void	window_initialisation(char *window_name)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_DisplayMode current;
    SDL_GetDesktopDisplayMode(0, &current);
    window = SDL_CreateWindow(window_name,
                               SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               current.w/1.2, current.h/1.2, SDL_WINDOW_OPENGL);
	window_size = t_vect_new(0, 0);
	SDL_GetWindowSize(window, &window_size->x, &window_size->y);
	TTF_Init();
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_WarpMouseInWindow(window, window_size->x / 2, window_size->y / 2);
    SDL_SetWindowGrab(window, SDL_FALSE);
    SDL_ShowCursor(1);
	set_color_tab();
}

SDL_Renderer *get_renderer()
{
	return (renderer);
}

t_vect  *get_win_size()
{
    return (window_size);
}

void close_renderer()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void error_exit(char *msg, int error)
{
	ft_printf("Error %d : %s\n", error, msg);
	exit(error);
}

void check_frame()
{
	unsigned int	framedelay = 1000 / FPS;
	int				frame_actual;
	static Uint32	framestart;
	static int		beginsecond;
	static int		nb_frame;

	frame_actual = SDL_GetTicks();
	if (beginsecond == 0)
		beginsecond = frame_actual;
	if (frame_actual - beginsecond > 1000)
	{
		ft_printf("FPS = %d\n", nb_frame);
		nb_frame = 0;
		beginsecond = 0;
	}
	else
		nb_frame++;
	if (framedelay > (frame_actual - framestart))
		SDL_Delay(framedelay - (frame_actual - framestart));
    framestart = SDL_GetTicks();
}

void	render_screen()
{
	check_frame();
	SDL_RenderPresent(get_renderer());
}
