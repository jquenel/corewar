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

static void control_input(t_state *state)
{
	if (state->event.type == SDL_QUIT)
		state->state = 0;
	if ( state->event.type == SDL_KEYUP && state->event.key.keysym.sym == SDLK_ESCAPE)
		state->state = 0;
}

void update_input(t_state *state)
{
	if (SDL_PollEvent(&(state->event)) == 1)
		control_input(state);
}
