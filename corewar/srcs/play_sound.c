/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/04 19:13:33 by jboissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

#define MUSIC_TIME		3500
#define MUSIC_DELAY		1500

static int		check_skip(void)
{
	SDL_Event event;

	if (SDL_PollEvent(&event) == 1)
	{
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
		{
			Mix_HaltChannel(1);
			return (1);
		}
	}
	SDL_PumpEvents();
	SDL_FlushEvent(SDL_KEYDOWN);
	SDL_FlushEvent(SDL_MOUSEMOTION);
	return (0);
}

static int		play_channel(int channel, Mix_Chunk *intro)
{
	int			i;

	i = 0;
	Mix_PlayChannel(channel, intro, -1);
	if (Mix_Playing(channel) == 1)
	{
		while (i < MUSIC_TIME + MUSIC_DELAY)
		{
			if (i == MUSIC_TIME)
				Mix_FadeOutChannel(channel, MUSIC_DELAY);
			if (check_skip() == 1)
				return (4);
			i++;
			SDL_Delay(1);
		}
	}
	return (1);
}

int				play_sound(int channel, char *path)
{
	Mix_Chunk	*intro;

	intro = Mix_LoadWAV(path);
	if (intro != NULL)
		return (play_channel(channel, intro));
	SDL_Delay(MUSIC_DELAY);
	return (1);
}
