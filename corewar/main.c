#include "template.h"
#include "corewar.h"

static t_2d_coord *get_size(int	len)
{
	int		i;
	int		j;

	i = get_root(len);
	j = i;
	while (i * j < len)
		i++;
	printf("%d / %d\n", i, j);
	return (t_2d_coord_new(i, j));
}

void	usage(void)
{
	ft_putendl("Usage : corewar [-dump nbr_cycles] \
			[[-n number] champion1.cor] ...");
	exit (1);
}

static t_core *create_t_core(t_sen *core)
{
	t_core		*sdl_core;

	if (!(sdl_core = (t_core *)malloc(sizeof(t_core))))
		error_exit("Can't malloc a t_core", 152);
	sdl_core->field = core->arena.field;
	sdl_core->index = core->arena.field;
	sdl_core->len = core->arena.size;
	sdl_core->size = get_size(sdl_core->len);
	return (sdl_core);
}

int main(int argc, char **argv)
{
	t_core		*sdl_core;
	t_sen		core;

	if (argc < 3)
		usage();
	if (parser(argc - 1, &(argv[1]), &core))
		usage();
	window_initialisation("char *window_name");
	sdl_core = create_t_core(&core);
	while (1)
	{
		render_screen();
		update_input(sdl_core);
	}
	return (0);
}
