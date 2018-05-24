/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/17 13:09:22 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

static void		control_fps(SDL_Event *event, t_sen *core)
{
	if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_r)
		reset_visu(core->visu);
}

static void		control_input(SDL_Event *event, t_sen *core, int *alive)
{
	if (event->type == SDL_QUIT)
		*alive = 0;
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
		*alive = 0;
	else if (event->type == SDL_MOUSEWHEEL)
	{
		if (event->wheel.y > 0)
			core->visu->zoom *= 1.1;
		else if (event->wheel.y < 0)
			core->visu->zoom *= 0.9;
		set_texture_list(core->visu);
	}
	if (event->type == SDL_MOUSEMOTION &&
		event->button.button == SDL_BUTTON_LEFT)
	{
		core->visu->base_pos->x += event->motion.xrel;
		core->visu->base_pos->y += event->motion.yrel;
	}
}

void			final_control(t_sen *core, int *alive)
{
	SDL_Event event;

	if (SDL_PollEvent(&event) == 1)
	{
		control_fps(&event, core);
		control_input(&event, core, alive);
	}
	SDL_PumpEvents();
	SDL_FlushEvent(SDL_KEYDOWN);
	SDL_FlushEvent(SDL_MOUSEMOTION);
}
