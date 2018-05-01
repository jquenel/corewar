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

void draw_rectangle(t_2d_coord *coord, t_2d_coord *size, char *color_type)
{
	SDL_Rect			Rect;
	SDL_Color			color;

	Rect.x = coord->x;
	Rect.y = coord->y;
	Rect.w = size->x;
	Rect.h = size->y;
	color = get_color(color_type);
    SDL_SetRenderDrawColor(get_renderer(), color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(get_renderer(), &Rect);
}

void draw_border_rectangle(t_2d_coord *coord, t_2d_coord *size, char *color_type)
{
	SDL_Rect			Rect1;
	SDL_Rect			Rect2;
	SDL_Color			color1;
	SDL_Color			color2;

	Rect1.x = coord->x;
	Rect1.y = coord->y;
	Rect1.w = size->x;
	Rect1.h = size->y;
	color1 = get_color(color_type);
	color2 = create_color(color1.r + 35, color1.g + 35, color1.b + 35, color1.a);
    SDL_SetRenderDrawColor(get_renderer(), color1.r, color1.g, color1.b, color1.a);
    SDL_RenderFillRect(get_renderer(), &Rect1);
	Rect2.x = coord->x + Rect1.w/16;
	Rect2.y = coord->y + Rect1.h/16;
	Rect2.w = size->x - Rect1.w/8;
	Rect2.h = size->y - Rect1.h/8;
    SDL_SetRenderDrawColor(get_renderer(), color2.r, color2.g, color2.b, color2.a);
    SDL_RenderFillRect(get_renderer(), &Rect2);
}
