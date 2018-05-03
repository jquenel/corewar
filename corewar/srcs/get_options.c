#include "corewar.h"

int		get_options(int *argc, char ***argv, t_sen *core)
{
	int	i;

	if (*argc <= 1)
		return (-1);
	i = 0;
	while (i < *argc - 1 && (*argv)[i][0] == '-'
			&& ft_strcmp((*argv)[i], "-n"))
	{
		if (!ft_strcmp((*argv)[i], "-dump"))
		{
			if (!is_all_nums((*argv)[i + 1]) ||
			!(core->state.dump_limit = ft_atoi((*argv)[i + 1])))
				return (-1);
			core->opt |= OPT_DUMP;
			i += 2;
		}
		else if (!(ft_strcmp((*argv)[i], "-f"))
			|| !(ft_strcmp((*argv)[i], "-v")))
		{
			core->opt |= (1 << (int)((*argv)[i][1] - 'a'));
			i++;
		}
		else
			return (-1);
	}
	*argv += i;
	return ((*argc -= i));
}
