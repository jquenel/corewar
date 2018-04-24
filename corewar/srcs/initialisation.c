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

SDL_Renderer	*renderer = NULL;
SDL_Window		*window = NULL;
t_2d_coord		*window_size = NULL;
int		FPS;
int		framedelay;

void	window_initialisation(char *window_name)
{

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_DisplayMode current;
    SDL_GetDesktopDisplayMode(0, &current);
    window = SDL_CreateWindow(window_name,
                               SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               current.w/1.2, current.h/1.2, SDL_WINDOW_OPENGL);
	window_size = t_2d_coord_new(0, 0);
	SDL_GetWindowSize(window, &window_size->x, &window_size->y);
	TTF_Init();
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_WarpMouseInWindow(window, window_size->x / 2, window_size->y / 2);
	SDL_SetWindowGrab(window, SDL_TRUE);
	SDL_ShowCursor(1);
	FPS = 60;
	framedelay = 1000 / FPS;
}

t_2d_coord	*get_window_size()
{
	return (window_size);
}

t_2d_coord	*get_mouse_coord()
{
	t_2d_coord *coord;
	int x;
	int y;

	SDL_GetMouseState(&x, &y);
	coord = t_2d_coord_new(x, y);
	return (coord);
}

SDL_Renderer *get_renderer()
{
	return (renderer);
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
	int				frame_actual;
	static int		nb_frame = 0;
	static int		beginsecond = 0;
	static Uint32	framestart = 0;

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
	if ((unsigned int)framedelay > (frame_actual - framestart))
		SDL_Delay(framedelay - (frame_actual - framestart));
	framestart = SDL_GetTicks();
}

void	render_screen()
{
	check_frame();
	SDL_RenderPresent(get_renderer());
}