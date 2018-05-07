/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/07 17:31:07 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

static void		control_fps(SDL_Event *event, t_visu *visu)
{
	if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_LEFT)
		set_fps(-1);
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RIGHT)
		set_fps(1);
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_UP)
		set_fps(10);
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_DOWN)
		set_fps(-10);
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_r)
		reset_visu(visu);
}

static void		control_input(SDL_Event *event, t_visu *visu)
{
	if (event->type == SDL_QUIT)
		exit(0);
	else if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_ESCAPE)
		exit(0);
	else if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_p)
		visu->pause = (visu->pause == 0 ? 1 : 0);
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_s)
		visu->one_cycle = 1;
	else if (event->type == SDL_MOUSEWHEEL)
	{
		if (event->wheel.y > 0)
			visu->zoom *= 1.1;
		else if (event->wheel.y < 0)
			visu->zoom *= 0.9;
		set_texture_list(visu);
	}
	if (event->type == SDL_MOUSEMOTION &&
		event->button.button == SDL_BUTTON_LEFT)
	{
		visu->base_pos->x += event->motion.xrel;
		visu->base_pos->y += event->motion.yrel;
	}
}

void			update_input(t_visu *visu)
{
	SDL_Event event;

	if (SDL_PollEvent(&event) == 1)
	{
		control_fps(&event, visu);
		control_input(&event, visu);
	}
	SDL_PumpEvents();
	SDL_FlushEvent(SDL_KEYDOWN);
	SDL_FlushEvent(SDL_KEYUP);
	SDL_FlushEvent(SDL_MOUSEMOTION);
}
