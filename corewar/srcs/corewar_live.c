/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2018/05/10 21:44:50 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			corewar_live(t_sen *core, t_bo *actual, t_arg *args)
{
	int		i;
	int		nb_player;

	actual->live++;
	nb_player = dtoi(args[0].data, args[0].size);
	core->state.l_count++;
	i = 0;
	while (core->player[i].live != -2)
	{
		if (core->player[i].pnum == nb_player && core->player[i].live >= 0)
		{
			if (core->opt & OPT_VERB)
				ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
					nb_player, core->player[i].name);
			core->player[i].live++;
			core->player[i].live_last = core->state.c_total + 1;
			core->state.l_last = nb_player;
			return (1);
		}
		i++;
	}
	return (1);
}
