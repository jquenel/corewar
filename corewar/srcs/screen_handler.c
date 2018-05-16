/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/07 17:32:56 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

SDL_Renderer		*g_renderer;
SDL_Window			*g_window;
t_vect				*g_window_size;

void				window_initialisation(char *window_name)
{
	SDL_DisplayMode current;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GetDesktopDisplayMode(0, &current);
	g_window = SDL_CreateWindow(window_name,
						SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
						current.w / 1.2, current.h / 1.2, SDL_WINDOW_OPENGL);
	g_window_size = t_vect_new(0, 0);
	SDL_GetWindowSize(g_window, &g_window_size->x, &g_window_size->y);
	TTF_Init();
	Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_AllocateChannels(3);
	g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_WarpMouseInWindow(g_window, g_window_size->x / 2, g_window_size->y / 2);
	SDL_SetWindowGrab(g_window, SDL_FALSE);
	SDL_ShowCursor(1);
	set_color_tab();
	set_typo_tab();
}

SDL_Renderer		*get_renderer(void)
{
	return (g_renderer);
}

t_vect				*get_win_size(void)
{
	return (g_window_size);
}

void				close_renderer(void)
{
	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);
}

void				render_screen(int pause)
{
	if (!pause)
		check_frame();
	SDL_RenderPresent(get_renderer());
}
