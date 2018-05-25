/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduce_champions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 21:46:53 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/21 21:53:56 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			introduce_champions(t_sen *core)
{
	int		i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (*(core->player[i].name))
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			i + 1,
			core->player[i].weight,
			core->player[i].name,
			core->player[i].comment);
		i++;
	}
}
