/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 21:38:41 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/11 20:07:45 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline char	field_index(t_sen *core, int index)
{
	return (core->arena.field[index % core->arena.size]);
}

void		copy_data(t_sen *core, char *dest, int pc, int size)
{
	while (pc < 0)
		pc = core->arena.size + pc;
	while (size--)
		dest[size] = field_index(core, pc + size);
}
