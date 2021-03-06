/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:13:16 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/26 09:10:38 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "limits.h"

static int	parse_num(t_sen *core, char *arg)
{
	long	num;
	int		i;

	if (ft_strlen(arg) > 12)
		num_error(core);
	num = ft_atoi_base(arg, 10);
	if (num > INT_MAX || num < INT_MIN)
		num_error(core);
	i = 0;
	while (*(core->player[i].name))
	{
		if (core->player[i].pnum == (int)num)
			num_error(core);
		i++;
	}
	return ((int)num);
}

static int	get_player_num(int *argc, char ***argv, t_sen *core)
{
	int		num;
	int		i;

	if (!ft_strcmp((*argv)[0], "-n"))
	{
		num = parse_num(core, (*argv)[1]);
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

static void	init_proc(t_sen *core, t_bushi *player, t_bo *proc, int i)
{
	proc->carry = 0;
	proc->pc = (MEM_SIZE * i) / core->pcount;
	ft_memset(proc->reg, 0, REG_NUMBER * REG_SIZE);
	copy_pnum(&player->pnum, proc->reg[0]);
	proc->parent = player;
	if (core->proc)
		core->proc->prev = proc;
	proc->next = core->proc;
	proc->prev = NULL;
	core->proc = proc;
	proc->cycle = -1;
	proc->op = NULL;
	proc->live = 0;
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
	core->player[i].vic_ccount = 0;
	ft_memset(core->player[i].name, 0, PROG_NAME_LENGTH + 1);
	ft_memset(core->player[i].comment, 0, COMMENT_LENGTH + 1);
	ft_memset(core->player[i].vic_shout, 0, MAX_VIC_LEN + 1);
	init_proc(core, &core->player[i], proc, i);
	if (load_program(**argv, &core->arena, &core->player[i], proc))
		return (destroy_processes(core->proc));
	(*argv)++;
	(*argc)--;
	return (1);
}
