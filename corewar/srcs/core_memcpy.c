/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:54:47 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:12:52 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	core_memcpy(t_ban *arena, t_arg *src, t_arg *dest, int size)
{
	int		start1;
	int		start2;
	char	*s;
	char	*d;
	int		i;

	start1 = src->type == REG_CODE ? 0 : src->data - arena->field;
	start2 = dest->type == REG_CODE ? 0 : dest->data - arena->field;
	s = src->type == REG_CODE ? src->data : arena->field;
	d = dest->type == REG_CODE ? dest->data : arena->field;
	i = 0;
	while (i < size)
	{
		d[(start2 + i) % arena->size] = s[(start1 + i) % arena->size];
		i++;
	}
}

/*static void	regtomem(t_ban *arena, t_arg *src, t_arg *dest, int size)
{
	int		start;
	int		i;

	start = dest->data - arena->field;
	i = 0;
	while (i < size)
	{
		arena->field[(start + i) % arena->size] = src->data[i];
		i++;
	}
}*/


/*
void		core_memcpy(t_ban *arena, t_arg *src, t_arg *dest, int size)
{
	if (src->type == REG_CODE)
	{
		if (dest->type == REG_CODE)
			ft_memcpy(dest->data, src->data, size);
		else
			regtomem(arena, src, dest, size);
	}
	else
	{
		if (dest->type == REG_CODE)
			memtoreg(arena, src, dest, size);
		else
			memtomem(arena, src, dest, size);
	}
}
*/
