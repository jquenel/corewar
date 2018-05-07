/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 21:48:31 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/06 18:39:41 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "template.h"

#define NO_WINNER	"No winner today !\nNext time, try using REAL champions ?\n"

void		declare_winner(t_sen *core, t_visu *visu)
{
	int		i;

	if (core->state.l_last == core->arena.empty_char)
		ft_printf(NO_WINNER);
	else
	{
		i = 0;
		while (core->player[i].pnum != core->state.l_last)
			i++;
		ft_printf("Player %d(%s) won !\n", core->player[i].pnum,
				core->player[i].name);
	}
	if (core->opt & OPT_VISU)
	{
		(void)visu;
		close_renderer();
	}
}
