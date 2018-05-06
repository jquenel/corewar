#include "template.h"
#include "corewar.h"

void set_texture_list(t_core *core)
{
	int			i;
	char		*text;
	SDL_Surface	*surface;

	if (core->font != NULL)
		TTF_CloseFont(core->font);
	core->font_size = (core->unit / 1.8) * core->zoom;
	core->font = TTF_OpenFont(FONT_PATH, core->font_size);
	i = 0;
	while (i < 256)
	{
		text = ft_itoa_base(i, "0123456789abcdef");
		if (ft_strlen(text) < 2)
			ft_stradd_front("0", &text);
		surface = TTF_RenderText_Blended(core->font, text, get_color(BLACK));
		core->texture_list[i] = SDL_CreateTextureFromSurface(get_renderer(), surface);
		SDL_FreeSurface(surface);
		free(text);
		i++;
	}
}

void draw_player(t_sen *core, t_core *sdl_core, int cycles)
{
	static TTF_Font	*font = NULL;
	char			*text;
	int				i;
	t_2d_coord		coord;
	t_2d_coord		size;

	if (font == NULL)
		font = TTF_OpenFont(FONT_PATH, sdl_core->unit);
	coord.x = get_window_size()->x * 0.7;
	coord.y = 0;
	size.x = get_window_size()->x - coord.x;
	size.y = get_window_size()->y - coord.y;
	draw_rectangle(&coord, &size, DARK_GREY);
	coord.x = coord.x + sdl_core->unit;
	coord.y = coord.y + sdl_core->unit;
	text = ft_strdup("Cycles : ");
	ft_stradd_back(&text, ft_itoa(cycles));
	draw_text(text, &coord, LIGHT_GREY, font, "normal");
	free(text);
	coord.y = coord.y + sdl_core->unit * 2;
	draw_text("Players :", &coord, LIGHT_GREY, font, "normal");
	i = 0;
	coord.x = coord.x + sdl_core->unit * 2;
	while (core->player[i].live != -2)
	{
		coord.y = coord.y + sdl_core->unit * 2;
		text = ft_strdup("Player name : ");
		ft_stradd_back(&text, core->player[i].name);
		draw_text(text, &coord, sdl_core->p_color[core->player[i].pindex], font, "underline");
		coord.y = coord.y + sdl_core->unit * 2;
		text = ft_strdup("Player num : ");
		ft_stradd_back(&text, ft_itoa(core->player[i].pnum));
		draw_text(text, &coord, LIGHT_GREY, font, "normal");
		coord.y = coord.y + sdl_core->unit * 2;
		text = ft_strdup("This player ");
		if (core->player[i].live == 1)
			ft_stradd_back(&text, "is alive this cycle");
		else
			ft_stradd_back(&text, "isn't alive this cycle");
		draw_text(text, &coord, LIGHT_GREY, font, "normal");
		coord.y = coord.y + sdl_core->unit * 2;
		free(text);
		i++;
	}
	(void)sdl_core;
}

void draw_pc(t_sen *core, t_core *sdl_core)
{
	t_bo	*tmp;
	int		pos;
	int		i;
	int		j;
	t_2d_coord	coord;
	t_2d_coord	size;

	size.x = (sdl_core->unit) * sdl_core->zoom;
	size.y = sdl_core->unit * sdl_core->zoom;
	tmp = core->proc;
	while (tmp != NULL)
	{
		j = tmp->pc / sdl_core->tab_size->y;
		i = tmp->pc - (j * sdl_core->tab_size->x);
		coord.x = (sdl_core->base_pos->x + (i * (sdl_core->unit + sdl_core->space)) + sdl_core->space / 2) * sdl_core->zoom;
		coord.y = (sdl_core->base_pos->y + (j * (sdl_core->unit + sdl_core->space)) + sdl_core->space / 2) * sdl_core->zoom;
		if (coord.x + (sdl_core->unit) * sdl_core->zoom >= 0 && coord.x < get_window_size()->x && coord.y + sdl_core->unit * sdl_core->zoom >= 0 && coord.y < get_window_size()->y)
		{
			pos = i + (j * sdl_core->tab_size->x);
			draw_border_rectangle(&coord, &size, sdl_core->p_color[(int)(sdl_core->index[pos])] + 1);
			coord.x = coord.x + ((sdl_core->unit / 2) * sdl_core->zoom);
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
	size.x = core->unit * core->zoom;
	size.y = core->unit * core->zoom;
	i = 0;
	while (i < core->tab_size->x)
	{
		j = 0;
		while (j < core->tab_size->y)
		{
			coord.x = (core->base_pos->x + (i * (core->unit + core->space)) + core->space / 2) * core->zoom;
			coord.y = (core->base_pos->y + (j * (core->unit + core->space)) + core->space / 2) * core->zoom;
			if (coord.x + (core->unit * 2) * core->zoom >= 0 && coord.x < get_window_size()->x && coord.y + core->unit * core->zoom >= 0 && coord.y < get_window_size()->y)
			{
				pos = i + (j * core->tab_size->x);
				draw_border_rectangle(&coord, &size, core->p_color[(int)(core->index[pos])]);
				coord.x = coord.x + (size.x / 2);
				coord.y = coord.y + (size.y / 2);
				draw_centred_SDLTexture(core->texture_list[ft_abs(core->field[pos])], &coord, 0);
			}
			j++;
		}
		i++;
	}
}
