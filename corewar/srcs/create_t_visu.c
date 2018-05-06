#include "template.h"
#include "corewar.h"

static t_vect *get_size(int	len)
{
	int		i;
	int		j;

	i = get_root(len);
	j = i;
	while (i * j < len)
		i++;
	return (t_vect_new(i, j));
}

static void define_base(t_visu *visu)
{
	int i;
	int j;

	i = get_win_size()->x / visu->tab_size->x;
	if (get_win_size()->y / visu->tab_size->y < i)
		i = get_win_size()->y / visu->tab_size->y;
	visu->space = i / 6;
	visu->unit = i - visu->space;
	i = (visu->unit + visu->space) * visu->tab_size->x + visu->space;
	j = (visu->unit + visu->space) * visu->tab_size->y + visu->space;
	visu->base_pos = t_vect_new((get_win_size()->x * 0.7) / 2 - i / 2,
									get_win_size()->y / 2 - j / 2);
	visu->zoom = 1;
	visu->font = NULL;
    set_texture_list(visu);
}

t_visu *create_t_visu(t_sen *visu)
{
	t_visu		*sdl_visu;

	if (!(sdl_visu = (t_visu *)malloc(sizeof(t_visu))))
		error_exit("Can't malloc a t_visu", 152);
	sdl_visu->field = visu->arena.field;
	sdl_visu->index = visu->arena.trace;
	sdl_visu->len = visu->arena.size;
	sdl_visu->tab_size = get_size(sdl_visu->len);
	sdl_visu->p_color[0] = GREY;
	sdl_visu->p_color[1] = P1_COLOR;
	sdl_visu->p_color[2] = P2_COLOR;
	sdl_visu->p_color[3] = P3_COLOR;
	sdl_visu->p_color[4] = P4_COLOR;
	define_base(sdl_visu);
	sdl_visu->menu_font = TTF_OpenFont(FONT_PATH, sdl_visu->unit);
	return (sdl_visu);
}
