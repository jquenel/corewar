/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/17 12:20:24 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

int			g_fps = 60;

void		set_fps(int i)
{
	if (g_fps + i < 24)
		g_fps = 24;
	else if (g_fps + i > 800)
		g_fps = 800;
	else
		g_fps += i;
}

void		reset_fps(int i)
{
	g_fps = i;
}

int			get_fps(void)
{
	return (g_fps);
}

void		check_frame(void)
{
	unsigned int	framedelay;
	int				frame_actual;
	static Uint32	framestart;
	static int		beginsecond;
	static int		nb_frame;

	framedelay = 1000 / g_fps;
	frame_actual = SDL_GetTicks();
	if (beginsecond == 0)
		beginsecond = frame_actual;
	if (frame_actual - beginsecond > 1000)
	{
		printf("FPS = %d\n", nb_frame);
		nb_frame = 0;
		beginsecond = 0;
	}
	else
		nb_frame++;
	if (framedelay > frame_actual - framestart)
		SDL_Delay(framedelay - (frame_actual - framestart));
	framestart = SDL_GetTicks();
}
