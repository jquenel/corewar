/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:40:55 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/26 09:09:02 by jquenel          ###   ########.fr       */
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

static int	load_error(char *error, char *file)
{
	ft_printf("\n%s (%s)\n\n", error, file);
	return (1);
}

int			load_program(char *file, t_ban *arena, t_bushi *player, t_bo *proc)
{
	int			fd;
	t_header	h;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (load_error("ERROR : Could not open file.", file));
	if (read(fd, &h, sizeof(t_header)) != sizeof(t_header))
		return (load_error("ERROR : Invalid file header.", file));
	if (h.magic != COREWAR_EXEC_MAGIC)
		return (load_error("ERROR : Invalid magic in file header.", file));
	ft_strncpy(player->name, h.prog_name, PROG_NAME_LENGTH);
	ft_strncpy(player->comment, h.comment, COMMENT_LENGTH);
	if (h.must_be_null != 0 || h.must_also_be_null != 0)
		return (load_error("ERROR: Invalid file header.", file));
	if ((h.prog_size = get_prog_size(h.prog_size)) > CHAMP_MAX_SIZE
			|| h.prog_size <= 2)
		return (load_error("ERROR : Bad program size.", file));
	if (read(fd, arena->field + proc->pc, h.prog_size + 1) != h.prog_size)
		return (load_error("ERROR : Bad program size.", file));
	ft_memset(arena->trace + proc->pc, player->pindex, h.prog_size);
	player->weight = h.prog_size;
	return (0);
}
