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
	visu->font_size = (visu->unit / 1.8) * visu->zoom;
	visu->font = TTF_OpenFont(FONT_PATH, visu->font_size);
	i = 0;
	while (i < 256)
	{
		text = ft_itoa_base(i, "0123456789abcdef");
		if (ft_strlen(text) < 2)
			ft_stradd_front("0", &text);
		surface = TTF_RenderText_Blended(visu->font, text, get_color(BLACK));
		visu->texture_list[i] = SDL_CreateTextureFromSurface(get_renderer(),
																	surface);
		SDL_FreeSurface(surface);
		free(text);
		i++;
	}
}
