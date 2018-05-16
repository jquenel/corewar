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
#include "corewar.h"

void			set_texture_list(t_visu *visu)
{
	int			i;
	char		*text;
	SDL_Surface	*surface;

	if (visu->font != NULL)
		TTF_CloseFont(visu->font);
	visu->font_size = (visu->unit / 1.55) * visu->zoom;
	visu->font = TTF_OpenFont(FONT_PATH, visu->font_size);
	TTF_SetFontStyle(visu->font, get_typo(BOLD));
	i = 0;
	while (i < 256)
	{
		text = ft_itoa_base(i, "0123456789abcdef");
		while (ft_strlen(text) < 2)
			ft_stradd_front("0", &text);
		surface = TTF_RenderText_Blended(visu->font, text, get_color(BLACK));
		visu->texture_list[i] = SDL_CreateTextureFromSurface(get_renderer(),
																	surface);
		SDL_FreeSurface(surface);
		free(text);
		i++;
	}
	TTF_SetFontStyle(visu->font, get_typo(NORMAL));
}

void			set_texture_menu_list(t_visu *visu)
{
	int			i;
	char		*text;
	SDL_Surface	*surface;

	i = 0;
	while (i < 256)
	{
		text = ft_itoa_base(i, "0123456789abcdef");
		while (ft_strlen(text) < 2)
			ft_stradd_front("0", &text);
		surface = TTF_RenderText_Blended(visu->menu_font, text,
															get_color(BLACK));
		visu->texture_menu_list[i] =
						SDL_CreateTextureFromSurface(get_renderer(), surface);
		SDL_FreeSurface(surface);
		free(text);
		i++;
	}
	SDL_QueryTexture(visu->texture_menu_list[(visu->select_proc->reg[0][0])],
					NULL, NULL, &(visu->print_size.x), &(visu->print_size.y));
}
