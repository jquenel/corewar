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

void			draw_rectangle(t_vect *coord, t_vect *size, int color_type)
{
	SDL_Rect			rect;
	SDL_Color			color;

	rect.x = coord->x;
	rect.y = coord->y;
	rect.w = size->x;
	rect.h = size->y;
	color = get_color(color_type);
	SDL_SetRenderDrawColor(get_renderer(), color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(get_renderer(), &rect);
}

void			draw_border_rectangle(t_vect *coord, t_vect *size,
																int color_type)
{
	SDL_Rect			rect1;
	SDL_Rect			rect2;
	SDL_Color			color1;
	SDL_Color			color2;
	int					border_size;

	rect1.x = coord->x;
	rect1.y = coord->y;
	rect1.w = size->x;
	rect1.h = size->y;
	color1 = get_color(color_type);
	color2 = get_color(color_type - 1);
	SDL_SetRenderDrawColor(get_renderer(), color1.r, color1.g, color1.b,
																	color1.a);
	SDL_RenderFillRect(get_renderer(), &rect1);
	border_size = rect1.w / 12 < rect1.h / 12 ? rect1.w / 12 : rect1.h / 12;
	rect2.x = coord->x + border_size;
	rect2.y = coord->y + border_size;
	rect2.w = size->x - border_size * 2;
	rect2.h = size->y - border_size * 2;
	SDL_SetRenderDrawColor(get_renderer(), color2.r, color2.g, color2.b,
																	color2.a);
	SDL_RenderFillRect(get_renderer(), &rect2);
}
