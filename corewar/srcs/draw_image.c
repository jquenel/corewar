/* ************************************************************************** */
/*                                                                            */
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

void			draw_image(char *path, t_vect *coord, t_vect *size,
																double angle)
{
	SDL_Surface		*bmp;
	SDL_Texture		*texture;
	SDL_Rect		dstrect;

	bmp = IMG_Load(path);
	if (!bmp)
		error_exit("Can't draw bmp", 1555);
	dstrect.x = coord->x;
	dstrect.y = coord->y;
	dstrect.w = size->x;
	dstrect.h = size->y;
	texture = SDL_CreateTextureFromSurface(get_renderer(), bmp);
	SDL_FreeSurface(bmp);
	if (!texture)
		error_exit("Can't draw texture", 2555);
	SDL_RenderCopyEx(get_renderer(), texture, NULL, &dstrect, angle, NULL,
																SDL_FLIP_NONE);
	SDL_DestroyTexture(texture);
}

void			draw_sdlsurface(SDL_Surface *bmp, t_vect *coord, t_vect *size,
																double angle)
{
	SDL_Texture		*texture;
	SDL_Rect		dstrect;

	if (!bmp)
		error_exit("Can't draw sdl surface", 1555);
	dstrect.x = coord->x;
	dstrect.y = coord->y;
	dstrect.w = size->x;
	dstrect.h = size->y;
	texture = SDL_CreateTextureFromSurface(get_renderer(), bmp);
	if (!texture)
		error_exit("Can't draw texture", 2555);
	SDL_RenderCopyEx(get_renderer(), texture, NULL, &dstrect, angle, NULL,
																SDL_FLIP_NONE);
	SDL_DestroyTexture(texture);
}

void			draw_sdltexture(SDL_Texture *texture, t_vect *coord,
													t_vect *size, double angle)
{
	SDL_Rect		dstrect;

	dstrect.x = coord->x;
	dstrect.y = coord->y;
	dstrect.w = size->x;
	dstrect.h = size->y;
	SDL_RenderCopyEx(get_renderer(), texture, NULL, &dstrect, angle, NULL,
																SDL_FLIP_NONE);
}

void			draw_centred_sdltexture(SDL_Texture *texture,
													t_vect *coord, double angle)
{
	SDL_Rect		dstrect;
	int				texw;
	int				texh;

	SDL_QueryTexture(texture, NULL, NULL, &texw, &texh);
	dstrect.x = coord->x - texw / 2;
	dstrect.y = coord->y - texh / 2;
	dstrect.w = texw;
	dstrect.h = texh;
	SDL_RenderCopyEx(get_renderer(), texture, NULL, &dstrect, angle, NULL,
																SDL_FLIP_NONE);
}
