/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:40:55 by jquenel           #+#    #+#             */
/*   Updated: 2018/04/24 23:18:34 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_prog_size(int size)
{
	return (((size >> 24) & (int)0xff)
			+ ((size >> 8) & ((int)0xff << 8))
			+ ((size << 8) & ((int)0xff << 16))
			+ ((size << 24) & ((int)0xff << 24)));
}

int			load_program(char *file, t_ban *arena, t_bushi *player, t_bo *proc)
{
	int			fd;
	t_header	h;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	if (read(fd, &h, sizeof(t_header)) != sizeof(t_header))
		return (1);
	if (h.magic != COREWAR_EXEC_MAGIC)
		return (1);
	ft_strncpy(player->name, h.prog_name, PROG_NAME_LENGTH);
	ft_strncpy(player->comment, h.comment, COMMENT_LENGTH);
	h.prog_size = get_prog_size(h.prog_size);
	if (read(fd, arena->field + proc->pc, h.prog_size + 1) != h.prog_size)
		return (1);
	return (0);
}
