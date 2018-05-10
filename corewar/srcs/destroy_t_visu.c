/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_getlvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:48:39 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/07 16:57:00 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"
#include "corewar.h"

void		destroy_t_visu(t_visu *visu)
{
	int i;

	TTF_CloseFont(visu->font);
	TTF_CloseFont(visu->menu_font);
	i = 0;
	while (i < 256)
		SDL_DestroyTexture(visu->texture_list[i++]);
	t_vect_free(visu->tab_size);
	t_vect_free(visu->base_pos);
}
