#include "corewar.h"

void		cycle(t_sen *core, t_optab op[OP_COUNT + 1])
{
	t_bo	*tmp;

	tmp = core->proc;
	while (tmp)
	{
		if (tmp->cycle < 0)
			tmp->cycle = plan_op(core, tmp, op);
		else if (tmp->cycle == 0)
			do_op(core, tmp);
		tmp->cycle--;
		tmp = tmp->next;
	}
}
