#include "corewar.h"

#define FIELD_INDEX(x)		FIELD[(int)x % core->arena.size]
#define CODE_BYTE			FIELD_INDEX(actual->pc + 1)

void		copy_data(t_sen *core, char *dest, int pc, int size)
{
	while (pc < 0)
		pc = core->arena.size + pc;
	while (size--)
		dest[size] = FIELD_INDEX(pc + size);
}
