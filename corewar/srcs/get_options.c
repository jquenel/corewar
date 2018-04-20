#include "corewar.h"

int		get_options(int *argc, char ***argv, t_sen *core)
{
	int	n;

	if (*argc <= 1)
		return (0);
	if (ft_strcmp((*argv)[0], "-dump"))
		return (0);
	if ((n = get_dump_limit((*argv)[1]) < 0))
		return (-1);
	core->state.dump_limit = n;
	*argc -= 2;
	*argv = &((*argv)[2]);
	return (2);
}
