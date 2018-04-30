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
	/*DEPENDING ON ENDIANNESS...
	j = sizeof(int);
	while (i-- && j--)
		reg[i] = ((char *)pnum)[j];
	*/
	j = 0;
	while (i-- && (unsigned int)j < sizeof(int))
		reg[i] = ((char *)pnum)[j++];
}

static void	change_empty_char(t_sen *core, int pcount)
{
	int		i;
	int		f;
	char	tmp;

	tmp = core->arena.empty_char;
	f = 1;
	while (f)
	{
		f = 0;
		i = pcount;
		while (i--)
			if ((int)core->arena.empty_char == core->player[i].pnum)
			{
				f = 1;
				i = 0;
				core->arena.empty_char--;
			}
	}
	i = core->arena.size;
	while (i--)
	{
		if (core->arena.trace[i] == tmp)
			core->arena.trace[i] = core->arena.empty_char;
	}
}

int			create_player(int *argc, char ***argv, t_sen *core, int i)
{
	t_bo		*proc;

	if (!(proc = malloc(sizeof(t_bo))))
		malloc_error(core);
	if ((core->player[i].pnum = get_player_num(argc, argv, core))
		== core->arena.empty_char)
		change_empty_char(core, i + 1);
	core->player[i].live = 0;
	proc->carry = 0;
	proc->pc = (MEM_SIZE * i) / core->pcount;
	copy_pnum(&core->player[i].pnum, proc->reg[0]);
	proc->pnum = core->player[i].pnum;
	proc->next = core->proc;
	core->proc = proc;
	if (load_program(**argv, &core->arena, &core->player[i], proc))
		return (destroy_processes(core->proc));
	(*argv)++;
	(*argc)--;
	return (proc->pnum);
}
