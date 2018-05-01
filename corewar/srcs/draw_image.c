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

void draw_image(char *path, t_2d_coord *coord, t_2d_coord *size, double angle)
{
	SDL_Surface		*bmp;
	SDL_Texture		*texture;
	SDL_Rect		dstrect;

	bmp = IMG_Load(path);
	if(!bmp)
		error_exit("Can't draw bmp", 1555);
	dstrect.x = coord->x;
	dstrect.y = coord->y;
	dstrect.w = size->x;
	dstrect.h = size->y;
	texture = SDL_CreateTextureFromSurface( get_renderer(), bmp );
	SDL_FreeSurface(bmp);
	if(!texture)
		error_exit("Can't draw texture", 2555);
	SDL_RenderCopyEx(get_renderer(), texture, NULL, &dstrect, angle, NULL, SDL_FLIP_NONE);
	SDL_DestroyTexture(texture);
}

void draw_SDLSurface(SDL_Surface *bmp, t_2d_coord *coord, t_2d_coord *size, double angle)
{
	SDL_Texture		*texture;
	SDL_Rect		dstrect;

	if(!bmp)
		error_exit("Can't draw sdl surface", 1555);
	dstrect.x = coord->x;
	dstrect.y = coord->y;
	dstrect.w = size->x;
	dstrect.h = size->y;
	texture = SDL_CreateTextureFromSurface( get_renderer(), bmp );
	if(!texture)
		error_exit("Can't draw texture", 2555);
	SDL_RenderCopyEx(get_renderer(), texture, NULL, &dstrect, angle, NULL, SDL_FLIP_NONE);
	SDL_DestroyTexture(texture);
}

void draw_SDLTexture(SDL_Texture *texture, t_2d_coord *coord, t_2d_coord *size, double angle)
{
	SDL_Rect		dstrect;
	
	dstrect.x = coord->x;
	dstrect.y = coord->y;
	dstrect.w = size->x;
	dstrect.h = size->y;
	SDL_RenderCopyEx(get_renderer(), texture, NULL, &dstrect, angle, NULL, SDL_FLIP_NONE);
}

void draw_centred_SDLTexture(SDL_Texture *texture, t_2d_coord *coord, double angle)
{
	SDL_Rect		dstrect;
	int				texW = 0;
	int				texH = 0;

	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	dstrect.x = coord->x - texW / 2;
	dstrect.y = coord->y - texH / 2;
	dstrect.w = texW;
	dstrect.h = texH;
	SDL_RenderCopyEx(get_renderer(), texture, NULL, &dstrect, angle, NULL, SDL_FLIP_NONE);
}
