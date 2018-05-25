/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduce_champions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 21:46:53 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/25 22:31:40 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			introduce_champions(t_sen *core)
{
	int		i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while ((core->player[i].live) != -2)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			core->player[i].pnum,
			core->player[i].weight,
			core->player[i].name,
			core->player[i].comment);
		i++;
	}
}
