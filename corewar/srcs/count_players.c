#include "corewar.h"

int		count_players(int argc, char **argv)
{
	int	i;
	int	pc;

	i = 0;
	pc = 0;
	while (i < argc)
	{
		if ((ft_strcmp(argv[i], "-n")))
		{
			if (argv[i][0] == '-')
				return (-1);
		}
		else
		{
			i++;
			if (i >= argc || !is_all_nums(argv[i]))
				return (-1);
			i++;
			if (i >= argc || argv[i][0] == '-')
				return (-1);
		}
		if (++pc > MAX_PLAYERS)
			return (-1);
		i++;
	}
	return (pc);
}
