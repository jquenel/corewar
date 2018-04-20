#include "corewar.h"

int		destroy_processes(t_bo *proc)
{
	t_bo	*tmp;

	while (proc)
	{
		tmp = proc;
		proc = proc->next;
		free(tmp);
	}
	return (-1);
}
