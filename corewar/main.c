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
	size = t_2d_coord_new(i - core->space, i - core->space);
	i = (size->x + core->space) * core->size->x;
	j = (size->y + core->space) * core->size->y;
	core->start = t_2d_coord_new((get_window_size()->x - i) / 2 + core->space/2, (get_window_size()->y - j) / 2 + core->space/2);
	return (size);
}

static void		draw_corewar(t_core	*core)
{
	int			i;
	int			j;
	t_2d_coord	*size;
	t_2d_coord	*coord;

	i = 0;
	size = get_square_size(core);
	coord = t_2d_coord_new(core->start->x, core->start->y);
	while (i < core->size->x)
	{
		j = 0;
		while (j < core->size->y && (i + (core->size->x * j)) < core->len)
		{
			draw_rectangle(coord, size, "blue");
			t_2d_coord_actualize(coord, coord->x, coord->y + size->y + core->space);
			j++;
		}
		t_2d_coord_actualize(coord, coord->x + size->x + core->space, core->start->y);
		i++;
	}
}

static t_2d_coord *get_size(char *entry)
{
	int		len;
	int		i;
	int		j;

	len = ft_strlen(entry);
	i = get_root(len);
	j = i;
	while (i * j < len)
		i++;
	printf("%d / %d\n", i, j);
	return (t_2d_coord_new(i, j));
}

int main()
{
	t_state state;
	t_core	core;
	int		nb_process;

	window_initialisation("char *window_name");
	core.field = "qwertyuiopasdfghjklqwryuioasdfghjkqwertyuiosdfghjkxcvbnmsdfghjkertyuiosdfghjkrtyuihjkiuytrewsdfvbnjkjhgfsastyui";
	core.index = "00000000000sdfghjklqwryuioasdfghjkqwertyuiosdfghjkxcvbnmsdfghjkertyuiosdfghjkrtyuihjkiuytrewsdfvbnjk11111111111";
	core.len = ft_strlen(core.field);
	core.size = get_size(core.field);
	nb_process = 4;
	if (!(core.pc = (int *)malloc(sizeof(int) * nb_process)))
		return (1);
	state.state = 1;
	state.frame = 0;
	state.frame_state = 0;
	state.direction = 0;
	while (state.state == 1)
	{
		SDL_SetRenderDrawColor(get_renderer(), 40, 40, 40, 255);
		SDL_RenderClear(get_renderer());
		draw_corewar(&core);
		render_screen();
		update_input(&state);
	}
	return (0);
}
