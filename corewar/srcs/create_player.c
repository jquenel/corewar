/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:13:16 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/12 21:08:40 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_player_num(int *argc, char ***argv, t_sen *core)
{
	int		num;
	int		i;

	if (!ft_strcmp((*argv)[0], "-n"))
	{
		num = ft_atoi((*argv)[1]);
		*argv += 2;
		*argc -= 2;
	}
	else
	{
		num = 1;
		i = 0;
		while (*(core->player[i].name))
		{
			if (core->player[i].pnum == num)
			{
				num++;
				i = 0;
			}
			i++;
		}
	}
	return (num);
}

static void	copy_pnum(int *pnum, char *reg)
{
	int		i;
	int		j;

	i = REG_SIZE;
	j = 0;
	while (i-- && (unsigned int)j < sizeof(int))
		reg[i] = ((char *)pnum)[j++];
}

int			create_player(int *argc, char ***argv, t_sen *core, int i)
{
	t_bo		*proc;

	if (!(proc = malloc(sizeof(t_bo))))
		malloc_error(core, NULL);
	core->player[i].pnum = get_player_num(argc, argv, core);
	core->player[i].pindex = i + 1;
	core->player[i].live = 0;
	core->player[i].live_last = 0;
	core->player[i].proc_count = 1;
	proc->carry = 0;
	proc->pc = (MEM_SIZE * i) / core->pcount;
	ft_memset(proc->reg, 0, REG_NUMBER * REG_SIZE);
	copy_pnum(&core->player[i].pnum, proc->reg[0]);
	proc->parent = &core->player[i];
	core->proc->prev = proc;
	proc->next = core->proc;
	proc->prev = NULL;
	proc->cycle = -1;
	proc->op = NULL;
	core->proc = proc;
	if (load_program(**argv, &core->arena, &core->player[i], proc))
		return (destroy_processes(core->proc));
	(*argv)++;
	(*argc)--;
	return (1);
}
