/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:54:47 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:13:23 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		core_regtomem(t_ban *arena, char *src, int dest, int pnum)
{
	int			i;

	while (dest < 0)
		dest = arena->size + dest;
	i = 0;
	while (i < REG_SIZE)
	{
		arena->field[(dest + i) % arena->size] = src[i];
		arena->trace[(dest + i) % arena->size] = pnum;
		i++;
	}
}
