/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:50:37 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/09 17:51:35 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "template.h"

static void		draw_all(t_sen *core, t_visu *visu)
{
	draw_core(visu);
	draw_pc(core, visu);
	draw_menu(core, visu, core->state.c_count);
	draw_info(core, visu);
	render_screen(visu->pause);
}

void		draw_corewar(t_sen *core, t_visu *visu)
{
	visu->one_cycle = 0;
	if (visu->cycle_to_jump <= 0 && visu->pause == 0)
		draw_all(core, visu);
	else
		visu->cycle_to_jump--;
	update_input(visu);
	while (visu->pause == 1 && !visu->one_cycle && visu->cycle_to_jump <= 0)
	{
		if (visu->cycle_to_jump <= 0)
			draw_all(core, visu);
		else
			visu->cycle_to_jump--;
		draw_menu(core, visu, core->state.c_count);
		draw_info(core, visu);
		render_screen(visu->pause);
		update_input(visu);
	}
}
