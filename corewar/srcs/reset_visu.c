#include "template.h"

void		reset_visu(t_visu *visu)
{
	int		i;
	int		j;

	i = (visu->unit + visu->space) * visu->tab_size->x + visu->space;
	j = (visu->unit + visu->space) * visu->tab_size->y + visu->space;
	visu->base_pos->y = (get_win_size()->y / 2) - j / 2;
	visu->base_pos->x = (get_win_size()->x * 0.7) / 2 - i / 2;
	visu->zoom = 1;
	reset_fps(60);
	set_texture_list(visu);
}
