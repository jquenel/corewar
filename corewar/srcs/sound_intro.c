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

# define MUSIC_TIME		3500
# define MUSIC_DELAY	1500

void			sound_intro(t_sen *core, t_visu *visu)
{
	t_bushi		*player;
	Mix_Chunk	*intro;
	int			i;
	double		j;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		player = &(core->player[i]);
		intro = Mix_LoadWAV(player->comment);
		if (intro != NULL)
		{
			Mix_VolumeChunk(intro, MIX_MAX_VOLUME);
			Mix_PlayChannel(1, intro, -1);
			SDL_Delay(MUSIC_TIME);
			Mix_FadeOutChannel(1, MUSIC_DELAY);
			SDL_Delay(MUSIC_DELAY);
			Mix_HaltChannel(1);
		}
		i++;
	}
}
