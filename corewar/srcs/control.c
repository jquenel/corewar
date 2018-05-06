/* ************************************************************************** */
/*                                                                        */
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

static void control_camera(t_core *sdl_core)
{
	int		x;
	int		y;

	SDL_GetMouseState(&x , &y);
	if (x == 0 || x >= (get_window_size()->x * 0.7) - 1 || y == 0 || y == get_window_size()->y - 1)
	{
		if (x == 0)
			sdl_core->base_pos->x += 10 * sdl_core->zoom;
		if (x >= (get_window_size()->x * 0.7) - 1)
			sdl_core->base_pos->x += -10 * sdl_core->zoom;
		if (y == 0)
			sdl_core->base_pos->y += 10 * sdl_core->zoom;
		if (y == get_window_size()->y - 1)
			sdl_core->base_pos->y += -10 * sdl_core->zoom;
	}
}

static void control_input(SDL_Event *event, t_core *sdl_core)
{
	if (event->type == SDL_QUIT)
		exit(0);
	else if ( event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_ESCAPE)
		exit(0);
	else if (event->type == SDL_MOUSEWHEEL)
	{
		if (event->wheel.y > 0)
			sdl_core->zoom *= 1.1;
        else if (event->wheel.y < 0)
			sdl_core->zoom *= 0.9;
		set_texture_list(sdl_core);
	}
	if (event->type == SDL_MOUSEMOTION && event->button.button == SDL_BUTTON_LEFT)
	{
		sdl_core->base_pos->x += event->motion.xrel;
		sdl_core->base_pos->y += event->motion.yrel;
	}
}

void update_input(t_core *sdl_core)
{
	SDL_Event event;

	control_camera(sdl_core);
	if (SDL_PollEvent(&event) == 1)
	{
		control_input(&event, sdl_core);
	}
	SDL_PumpEvents();
	SDL_FlushEvent(SDL_MOUSEMOTION);
}
