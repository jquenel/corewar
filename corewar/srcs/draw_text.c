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

int				draw_text(char *text, t_vect *coord, t_typo *v_font)
{
	SDL_Color		color;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Rect		dstrect;

	TTF_SetFontStyle(v_font->font, get_typo(v_font->typo));
	color = get_color(v_font->color_type);
	surface = TTF_RenderText_Blended(v_font->font, text, color);
	texture = SDL_CreateTextureFromSurface(get_renderer(), surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = coord->x;
	dstrect.y = coord->y;
	SDL_RenderCopy(get_renderer(), texture, NULL, &dstrect);
	SDL_DestroyTexture(texture);
	return (dstrect.w);
}

int				draw_centred_text(char *text, t_vect *coord, t_typo *v_font)
{
	SDL_Color		color;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Rect		dstrect;

	TTF_SetFontStyle(v_font->font, get_typo(v_font->typo));
	color = get_color(v_font->color_type);
	surface = TTF_RenderText_Blended(v_font->font, text, color);
	texture = SDL_CreateTextureFromSurface(get_renderer(), surface);
	SDL_QueryTexture(texture, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = coord->x - (dstrect.w / 2);
	dstrect.y = coord->y - (dstrect.h / 2);
	SDL_FreeSurface(surface);
	SDL_RenderCopy(get_renderer(), texture, NULL, &dstrect);
	SDL_DestroyTexture(texture);
	return (dstrect.w);
}
