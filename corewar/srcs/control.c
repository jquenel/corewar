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
	if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_LEFT)
		set_fps(-1);
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RIGHT)
		set_fps(1);
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_UP)
		set_fps(10);
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_DOWN)
		set_fps(-10);
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_r)
		reset_visu(core->visu);
}

static void		control_input(SDL_Event *event, t_sen *core)
{
	if (event->type == SDL_QUIT)
		exit_corewar(core);
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
		exit_corewar(core);
	else if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_p)
		core->visu->pause = (core->visu->pause == 0 ? 1 : 0);
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_s)
		core->visu->one_cycle = 1;
	else if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_j)
		core->visu->cycle_to_jump += 1000.0f;
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

static void		control_selected(SDL_Event *event, t_sen *core)
{
	if (!core->visu->select_proc)
		return ;
	if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_KP_1)
	{
		if (core->visu->select_proc->prev != NULL)
			core->visu->select_proc = core->visu->select_proc->prev;
		else
		{
			while (core->visu->select_proc->next != NULL)
				core->visu->select_proc = core->visu->select_proc->next;
		}
	}
	else if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_KP_3)
	{
		if (core->visu->select_proc->next != NULL)
			core->visu->select_proc = core->visu->select_proc->next;
		else
		{
			while (core->visu->select_proc->prev != NULL)
				core->visu->select_proc = core->visu->select_proc->prev;
		}
	}
}

static void		control_help(SDL_Event *event, t_sen *core)
{
	if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_1)
	{
		core->visu->help = 1;
	}
	if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_1)
	{
		core->visu->help = 0;
	}
}

void			update_input(t_sen *core)
{
	SDL_Event event;

	if (SDL_PollEvent(&event) == 1)
	{
		control_fps(&event, core);
		control_input(&event, core);
		control_selected(&event, core);
	}
	control_help(&event, core);
	SDL_PumpEvents();
	SDL_FlushEvent(SDL_KEYDOWN);
	SDL_FlushEvent(SDL_MOUSEMOTION);
}
