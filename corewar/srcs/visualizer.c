#include "template.h"
#include "corewar.h"

static char *get_player_color(char i)
{
	if (i == 0)
		return ("blue");
	else if (i == 1)
		return ("red");
	else if (i == 2)
		return ("green");
	else if (i == 3)
		return ("orange");
	return ("grey");
}

void draw_core(t_core *core)
{
	int			i;
	int 		j;
	char		*text;
	int			pos;
	t_2d_coord	coord;
	t_2d_coord	size;

	SDL_SetRenderDrawColor(get_renderer(), 40, 40, 40, 255);
	SDL_RenderClear(get_renderer());
	if (core->font_size != (core->unit * 1.5) * core->zoom)
	{
		TTF_CloseFont(core->font);
		core->font = TTF_OpenFont(FONT_PATH, (core->unit * 1.2) * core->zoom);
	}
	size.x = (core->unit * 2) * core->zoom;
	size.y = core->unit * core->zoom;
	i = 0;
	while (i < core->tab_size->x)
	{
		j = 0;
		while (j < core->tab_size->y)
		{
			coord.x = (core->base_pos->x + (i * ((core->unit * 2) + core->space)) + core->space / 2) * core->zoom;
			coord.y = (core->base_pos->y + (j * (core->unit + core->space)) + core->space / 2) * core->zoom;
			if (coord.x + (core->unit * 2) * core->zoom >= 0 && coord.x < get_window_size()->x && coord.y + core->unit * core->zoom >= 0 && coord.y < get_window_size()->y)
			{
				pos = i + (j * core->tab_size->x);
				draw_border_rectangle(&coord, &size, get_player_color(core->index[pos]));
				coord.x = coord.x + (core->unit * core->zoom);
				coord.y = coord.y + ((core->unit / 2) * core->zoom);
				text = ft_itoa_base(ft_abs(core->field[pos]), "0123456789abcdef");
		        if (ft_strlen(text) < 2)
		            ft_stradd_front("0", &text);
				//draw_centred_text(text, &coord, "black", core->font, "normal");
				free(text);
			}
			j++;
		}
		i++;
	}
}
