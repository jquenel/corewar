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

SDL_Color create_color(int r, int g, int b, int a)
{
	SDL_Color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

SDL_Color get_color(char *color_type)
{
	SDL_Color color;

	if (!ft_strcmp(color_type, "black"))
		color = create_color(0, 0, 0, 42);
	else if (!ft_strcmp(color_type, "white"))
		color = create_color(255, 255, 255, 42);
	else if (!ft_strcmp(color_type, "red"))
		color = create_color(255, 0, 0, 42);
	else if (!ft_strcmp(color_type, "green"))
		color = create_color(0, 255, 0, 42);
	else if (!ft_strcmp(color_type, "blue"))
		color = create_color(0, 0, 255, 42);
	else if (!ft_strcmp(color_type, "grey"))
		color = create_color(156, 156, 156, 42);
	else if (!ft_strcmp(color_type, "cyan"))
		color = create_color(0, 255, 255, 42);
	else
		color = create_color(0, 0, 0, 42);
	return color;
}

static int		get_typo(char *typo)
{
	if (!ft_strcmp(typo, "bold"))
		return (TTF_STYLE_BOLD);
	else if (!ft_strcmp(typo, "italic"))
		return (TTF_STYLE_ITALIC);
	else if (!ft_strcmp(typo, "underline"))
		return (TTF_STYLE_UNDERLINE);
	else if (!ft_strcmp(typo, "stricke"))
		return (TTF_STYLE_STRIKETHROUGH);
	return (0);
}

int			draw_text(char *text, int size, t_2d_coord *coord, char *color_type, char *typo)
{
	TTF_Font		*font;
	SDL_Color		color;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Rect		dstrect;
	int				texW = 0;
	int				texH = 0;

	font = TTF_OpenFont(FONT_PATH, size);
	TTF_SetFontStyle(font, get_typo(typo));
	color = get_color(color_type);
	surface = TTF_RenderText_Blended(font, text, color);
	texture = SDL_CreateTextureFromSurface(get_renderer(), surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	dstrect.x = coord->x;
	dstrect.y = coord->y;
	dstrect.w = texW;
	dstrect.h = texH;
	SDL_RenderCopy(get_renderer(), texture, NULL, &dstrect);
	TTF_CloseFont(font);
	SDL_DestroyTexture(texture);
	return (texW);
}

int			draw_centred_text(char *text, int size, t_2d_coord *coord, char *color_type, char *typo)
{
	TTF_Font		*font;
	SDL_Color		color;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Rect		dstrect;
	int				texW = 0;
	int				texH = 0;

	font = TTF_OpenFont(FONT_PATH, size);
	TTF_SetFontStyle(font, get_typo(typo));
	color = get_color(color_type);
	surface = TTF_RenderText_Blended(font, text, color);
	texture = SDL_CreateTextureFromSurface(get_renderer(), surface);
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	dstrect.x = coord->x;
	dstrect.y = coord->y;
	dstrect.w = texW;
	dstrect.h = texH;
	SDL_FreeSurface(surface);
	SDL_RenderCopy(get_renderer(), texture, NULL, &dstrect);
	TTF_CloseFont(font);
	SDL_DestroyTexture(texture);
	return (texW);
}
