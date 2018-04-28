#include "corewar.h"

#define FIELD_INDEX(x)		FIELD[(int)x % core->arena.size]
#define OP_BYTE				FIELD_INDEX(actual->pc)
#define CODE_BYTE			FIELD_INDEX(actual->pc + 1)

static void	copy_arg(t_sen *core, t_arg *arg, int pc)
{
	int		i;

	i = arg->size;
	while (i--)
		arg->data[i] = FIELD_INDEX(pc + i)
}

static void	input_types(t_sen *core, t_bo *actual)
{
	int		i;
	int		total;

	i = 0;
	total = 1;
	while (i < actual->op->arg_count)
	{
		actual->args[i].type = actual->op->arg_types[i];
		if (actual->args[i].type == T_REG)
			actual->args[i].size = REG_SIZE;
		else if (actual->args[i].type == T_DIR)
			actual->args[i].size = actual->op->extra & EX_IS ?
										IND_SIZE : DIR_SIZE;
		else if (actual->args[i].type == T_IND)
			actual->args[i].size = IND_SIZE;
		copy_arg(core, &actual->args[i], actual->pc + total);
		total += actual->args[i].size;
		i++;
	}
}

static void	decode_types(t_sen *core, t_bo *actual)
{
	int		i;

	i = actual->op->arg_count;
	while (i
}

void	plan_op(t_sen *core, t_bo *actual, t_optab op[OP_COUNT + 1])
{
	int		i;
	int		j;

	if (OP_BYTE < 1 || OP_BYTE > OP_COUNT)
	{
		actual->pc = (actual->pc + 1) % core->arena.size;
		return (0);
	}
	ft_memset(actual->args, 0, sizeof(t_arg) * (MAX_ARGS_NUMBER));
	actual->op = &op[(int)OP_BYTE - 1];
	if (actual->op->extra & EX_CD)
		decode_types(core, actual);
	else
		input_types(core, actual);
	return (actual->op->cycle);
}

int		cycle(t_sen *core, t_optab op[OP_COUNT + 1])
{
	t_bo	*tmp;

	tmp = core->proc;
	while (tmp)
	{
		if (tmp->cycle < 0)
			tmp->cycle = plan_op(core, tmp, op);
		else if (tmp->cycle == 0)
			do_op(core, tmp, op);
		tmp->cycle--;
		tmp = tmp->next;
	}
}
