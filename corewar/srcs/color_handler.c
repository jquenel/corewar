/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/07 17:32:56 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

SDL_Color			g_color_tab[NB_COLOR];

SDL_Color		create_color(int r, int g, int b, int a)
{
	SDL_Color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

void			set_color_tab(void)
{
	g_color_tab[BLACK] = create_color(39, 39, 39, 42);
	g_color_tab[WHITE] = create_color(240, 240, 240, 42);
	g_color_tab[LIGHT_BLUE] = create_color(135, 206, 250, 42);
	g_color_tab[BLUE] = create_color(30, 144, 255, 42);
	g_color_tab[DARK_BLUE] = create_color(0, 0, 139, 42);
	g_color_tab[LIGHT_RED] = create_color(221, 110, 110, 42);
	g_color_tab[RED] = create_color(165, 89, 89, 42);
	g_color_tab[DARK_RED] = create_color(110, 70, 70, 42);
	g_color_tab[LIGHT_GREEN] = create_color(170, 220, 115, 42);
	g_color_tab[GREEN] = create_color(89, 165, 89, 42);
	g_color_tab[DARK_GREEN] = create_color(30, 100, 60, 42);
	g_color_tab[LIGHT_CYAN] = create_color(127, 255, 212, 42);
	g_color_tab[CYAN] = create_color(64, 224, 208, 42);
	g_color_tab[DARK_CYAN] = create_color(0, 139, 139, 42);
	g_color_tab[LIGHT_GREY] = create_color(175, 175, 175, 42);
	g_color_tab[GREY] = create_color(86, 86, 86, 42);
	g_color_tab[DARK_GREY] = create_color(56, 56, 56, 42);
	g_color_tab[LIGHT_ORANGE] = create_color(255, 195, 0, 42);
	g_color_tab[ORANGE] = create_color(255, 165, 0, 42);
	g_color_tab[DARK_ORANGE] = create_color(255, 130, 0, 42);
}

SDL_Color		get_color(int i)
{
	if (i < 0 || i > NB_COLOR)
		return (g_color_tab[0]);
	return (g_color_tab[i]);
}
