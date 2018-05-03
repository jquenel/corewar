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

static char *get_pc_player_color(char i)
{
	if (i == 0)
		return ("dark blue");
	else if (i == 1)
		return ("dark red");
	else if (i == 2)
		return ("dark green");
	else if (i == 3)
		return ("dark orange");
	return ("grey");
}

void set_texture_list(t_core *core)
{
	int			i;
	char		*text;
	SDL_Surface	*surface;

	if (core->font != NULL)
		TTF_CloseFont(core->font);
	core->font_size = (core->unit * 1.5) * core->zoom;
	core->font = TTF_OpenFont(FONT_PATH, core->font_size);
	i = 0;
	while (i < 256)
	{
		text = ft_itoa_base(i, "0123456789abcdef");
		if (ft_strlen(text) < 2)
			ft_stradd_front("0", &text);
		surface = TTF_RenderText_Blended(core->font, text, get_color("black"));
		core->texture_list[i] = SDL_CreateTextureFromSurface(get_renderer(), surface);
		SDL_FreeSurface(surface);
		free(text);
		i++;
	}
}

void draw_pc(t_sen *core, t_core *sdl_core)
{
	t_bo	*tmp;
	int		pos;
	int		i;
	int		j;
	t_2d_coord	coord;
	t_2d_coord	size;

	size.x = (sdl_core->unit * 2) * sdl_core->zoom;
	size.y = sdl_core->unit * sdl_core->zoom;
	tmp = core->proc;
	while (tmp != NULL)
	{
		j = (tmp->pc / sdl_core->tab_size->y) - 1;
		i = tmp->pc - (j * sdl_core->tab_size->x);
		coord.x = (sdl_core->base_pos->x + (i * ((sdl_core->unit * 2) + sdl_core->space)) + sdl_core->space / 2) * sdl_core->zoom;
		coord.y = (sdl_core->base_pos->y + (j * (sdl_core->unit + sdl_core->space)) + sdl_core->space / 2) * sdl_core->zoom;
		if (coord.x + (sdl_core->unit * 2) * sdl_core->zoom >= 0 && coord.x < get_window_size()->x && coord.y + sdl_core->unit * sdl_core->zoom >= 0 && coord.y < get_window_size()->y)
		{
			pos = i + (j * sdl_core->tab_size->x);
			draw_border_rectangle(&coord, &size, get_pc_player_color(sdl_core->index[pos]));
			coord.x = coord.x + (sdl_core->unit * sdl_core->zoom);
			coord.y = coord.y + ((sdl_core->unit / 2) * sdl_core->zoom);
			draw_centred_SDLTexture(sdl_core->texture_list[ft_abs(sdl_core->field[pos])], &coord, 0);
		}
		tmp = tmp->next;
	}
}

void draw_core(t_core *core)
{
	int			i;
	int 		j;
	int			pos;
	t_2d_coord	coord;
	t_2d_coord	size;

	SDL_SetRenderDrawColor(get_renderer(), 40, 40, 40, 255);
	SDL_RenderClear(get_renderer());
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
				draw_centred_SDLTexture(core->texture_list[ft_abs(core->field[pos])], &coord, 0);
			}
			j++;
		}
		i++;
	}
}
