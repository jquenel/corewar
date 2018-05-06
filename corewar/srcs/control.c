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

static void control_camera(t_visu *visu)
{
	int		x;
	int		y;

	SDL_GetMouseState(&x , &y);
	if (x == 0 || x >= (get_win_size()->x * 0.7) - 1 || y == 0 || y == get_win_size()->y - 1)
	{
		if (x == 0)
			visu->base_pos->x += 10 * visu->zoom;
		if (x >= (get_win_size()->x * 0.7) - 1)
			visu->base_pos->x += -10 * visu->zoom;
		if (y == 0)
			visu->base_pos->y += 10 * visu->zoom;
		if (y == get_win_size()->y - 1)
			visu->base_pos->y += -10 * visu->zoom;
	}
}

static void control_input(SDL_Event *event, t_visu *visu)
{
	if (event->type == SDL_QUIT)
		exit(0);
	else if ( event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_ESCAPE)
		exit(0);
	else if (event->type == SDL_MOUSEWHEEL)
	{
		if (event->wheel.y > 0)
			visu->zoom *= 1.1;
        else if (event->wheel.y < 0)
			visu->zoom *= 0.9;
		set_texture_list(visu);
	}
	if (event->type == SDL_MOUSEMOTION && event->button.button == SDL_BUTTON_LEFT)
	{
		visu->base_pos->x += event->motion.xrel;
		visu->base_pos->y += event->motion.yrel;
	}
}

void update_input(t_visu *visu)
{
	SDL_Event event;

	control_camera(visu);
	if (SDL_PollEvent(&event) == 1)
	{
		control_input(&event, visu);
	}
	SDL_PumpEvents();
	SDL_FlushEvent(SDL_MOUSEMOTION);
}
