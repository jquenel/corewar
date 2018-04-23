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

#include "corewar.h"

void corewar_live(t_sen *arena, t_bo *actual, t_arg *arg_list)
{
	t_bushi *player;
	int		i;
	int		nb_player;

	if (arg_list[0] == NULL || arg[0]->type != 2)
		return ;
	nb_player = (int)(arg_list[0]->data);
	i = 0;
	player = NULL;
	while (arena->reg[i]->live != -2)
	{
		if (arena->reg[i]->pnum == (int)arg_list[0] && arena->reg[i]->live >= 0)
			player = arena->reg[i];
		i++;
	}
	if (player != NULL)
		ft_printf("le joueur %d(%s) est en vie\n", player->pnum, player->name);
}
