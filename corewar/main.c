#include "template.h"
#include "corewar.h"

static t_2d_coord *get_square_size(t_core *core)
{
	int			i;
	int			j;
	t_2d_coord	*size;

	i = get_window_size()->x / core->size->x;
	j = get_window_size()->y / core->size->y;
	if (i > j)
		i = j;
	core->space = i - (i / 1.2);
	core->text_size = i / 3;
	core->font = TTF_OpenFont(FONT_PATH, core->text_size);
	TTF_SetFontStyle(core->font, 0);
	size = t_2d_coord_new(i - core->space, i - core->space);
	i = (size->x + core->space) * core->size->x;
	j = (size->y + core->space) * core->size->y;
	core->start = t_2d_coord_new((get_window_size()->x - i) / 2 + core->space/2,
								(get_window_size()->y - j) / 2 + core->space/2);
	return (size);
}

static char		*get_player_color(int i)
{
	if (i == 0)
		return ("blue");
	else if (i == 1)
		return ("red");
	else if (i == 2)
		return ("green");
	else if (i == 3)
		return ("cyan");
	else
		return ("grey");
}

static void		draw_corewar(t_core	*core)
{
	int			i;
	int			j;
	t_2d_coord	*size;
	t_2d_coord	*coord;
	t_2d_coord	*text_coord;

	i = 0;
	size = get_square_size(core);
	coord = t_2d_coord_new(core->start->x, core->start->y);
	text_coord = t_2d_coord_new(0, 0);
	while (i < core->size->x)
	{
		j = 0;
		while (j < core->size->y && (i + (core->size->x * j)) < core->len)
		{
			t_2d_coord_actualize(text_coord, coord->x + size->x / 2, coord->y + size->y / 2);
			draw_border_rectangle(coord, size, get_player_color(core->index[i + (core->size->x * j)] - '0'));
			draw_centred_text(ft_itoa_base(core->field[i + (core->size->x * j)], 16), text_coord, "black", core->font, "normal");
			t_2d_coord_actualize(coord, coord->x, coord->y + size->y + core->space);
			j++;
		}
		t_2d_coord_actualize(coord, coord->x + size->x + core->space, core->start->y);
		i++;
	}
}

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

int main(int argc, char **argv)
{
	t_state state;
	t_core	sdl_core;
	int		nb_process;
	int		i;
	t_sen		core;

	if (argc < 3)
		usage();
	if (parser(argc - 1, &(argv[1]), &core))
		usage();
	window_initialisation("char *window_name");
	sdl_core.field = core.arena.field;
	sdl_core.index = core.arena.field;
	sdl_core.len = core.arena.size;
	printf("len = %d\n", sdl_core.len);
	sdl_core.size = get_size(sdl_core.len);
	nb_process = 4;
	if (!(sdl_core.pc = (int *)malloc(sizeof(int) * nb_process)))
		return (1);
	state.state = 1;
	state.frame = 0;
	state.frame_state = 0;
	state.direction = 0;
	i = 0;
	while (state.state == 1)
	{
		SDL_SetRenderDrawColor(get_renderer(), 40, 40, 40, 255);
		SDL_RenderClear(get_renderer());
		draw_corewar(&sdl_core);
		render_screen();
		update_input(&state);
		i++;
	}
	return (0);
}
