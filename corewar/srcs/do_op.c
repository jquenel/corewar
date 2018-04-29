#include "corewar.h"

static int	check_args_validity(t_bo *actual)
{
	int		i;

	i = actual->op->arg_count;
	while (i--)
	{
		if (!(actual->args[i].type & actual->op->arg_types[i]))
			return (0);
	}
	return (1);
}

void	do_op(t_sen *core, t_bo *actual)
{
	if (!check_args_validity(actual))
		actual->pc = (actual->pc + actual->size) % core->arena.size;
	else if (actual->op->op(core, actual, actual->args))
		actual->pc = (actual->pc + actual->size) % core->arena.size;
}
