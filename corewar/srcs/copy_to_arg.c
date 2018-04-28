#include "corewar.h"

#define FIELD_INDEX(x)		FIELD[(int)x % core->arena.size]
#define CODE_BYTE			FIELD_INDEX(actual->pc + 1)

void		copy_to_arg(t_sen *core, t_arg *arg, int pc)
{
	int		i;

	i = arg->size;
	while (i--)
		arg->data[i] = FIELD_INDEX(pc + i)
}
