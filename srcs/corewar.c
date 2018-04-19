#include "corewar.h"
#include <unistd.h>

void	usage(void)
{
	ft_putendl("Usage : corewar [-dump nbr_cycles] \
			[[-n number] champion1.cor] ...");
	exit (1);
}

int	main(int argc, char **argv)
{
	t_sen		core;

	if (argc < 3)
		usage();
	if (parser(argc - 1, &(argv[1]), &core))
		usage();
}