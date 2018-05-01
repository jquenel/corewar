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

static void control_input(SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		exit(0);
	else if ( event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_ESCAPE)
		exit(0);
	printf("Bouh haha\n");
}

void update_input(t_core *sdl_core)
{
	SDL_Event *event;

	(void)sdl_core;
	printf("a1\n");
	event = NULL;
	printf("a2\n");
	if (SDL_PollEvent(event) == 1 && event != NULL)
	{
		printf("a3\n");
		control_input(event);
		printf("a4\n");
	}
}
