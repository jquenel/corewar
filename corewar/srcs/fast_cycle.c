#include "corewar.h"

static void	cycle_all(t_bo *proc, int min)
{
	while (proc)
	{
		proc->cycle -= min;
		proc = proc->next;
	}
}

static int	get_min_cycle(t_bo *proc)
{
	int		min;

	min = INT_MAX;
	while (proc)
	{
		if (proc->cycle < min)
			min = proc->cycle;
		proc = proc->next;
	}
	return (min);
}

int			fast_cycle(t_sen *core, t_optab op[OP_COUNT + 1])
{
	t_bo	*tmp;

	cycle_all(core->proc, get_min_cycle(core->proc));
	tmp = core->proc;
	while (tmp)
	{
		if (tmp->cycle == 0)
		{
			if (tmp->op)
				do_op(core, tmp);
			tmp->cycle = plan_op(core, tmp, op);
		}
		tmp = tmp->next;
	}
	return (min);
}
