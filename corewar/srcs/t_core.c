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
	return (t_2d_coord_new(i, j));
}

static void define_base(t_core *core)
{
	int i;
	int j;

	i = get_window_size()->x / core->tab_size->x;
	if (get_window_size()->y / core->tab_size->y < i)
		i = get_window_size()->y / core->tab_size->y;
	core->space = i / 6;
	core->unit = i - core->space;
	i = (core->unit + core->space) * core->tab_size->x + core->space;
	j = (core->unit + core->space) * core->tab_size->y + core->space;
	core->base_pos = t_2d_coord_new(get_window_size()->x / 2 - i / 2,
									get_window_size()->y / 2 - j / 2);
	core->zoom = 1;
	core->font = NULL;
    set_texture_list(core);
}

t_core *create_t_core(t_sen *core)
{
	t_core		*sdl_core;

	if (!(sdl_core = (t_core *)malloc(sizeof(t_core))))
		error_exit("Can't malloc a t_core", 152);
	sdl_core->field = core->arena.field;
	sdl_core->index = core->arena.trace;
	sdl_core->len = core->arena.size;
	sdl_core->tab_size = get_size(sdl_core->len);
	sdl_core->p_color[0] = GREY;
	sdl_core->p_color[1] = P1_COLOR;
	sdl_core->p_color[2] = P2_COLOR;
	sdl_core->p_color[3] = P3_COLOR;
	sdl_core->p_color[4] = P4_COLOR;
	define_base(sdl_core);
	return (sdl_core);
}
