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

int		create_player(int *argc, char ***argv, t_sen *core, int i)
{
	int		i;
	t_bo		*proc;

	if (!(proc = malloc(sizeof(t_bo))))
		return (-1);
	pos =
	core->player[i].pnum = get_player_num(argc, argv, core);
	proc->carry = 0;
	proc->reg[0] = (MEM_SIZE * i) / core->pcount;
	proc->reg[1] = core->player[i].pnum;
	proc->pnum = core->player[i].pnum;
	proc->next = core->proc;
	core->proc = proc;
	if (load_program(**argv, core->arena, core->player[i], proc))
		return (destroy_processes(core->proc));
	(*argv)++;
	(*argc)--;
	return (proc->pnum);
}
