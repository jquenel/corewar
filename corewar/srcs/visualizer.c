#include "template.h"
#include "corewar.h"

void set_texture_list(t_visu *core)
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

static void draw_line(char *text, t_vect *coord, t_visu *visu,
																	int color)
{
	t_vect_actualize(coord, coord->x, coord->y + visu->unit * 2);
	draw_text(text, coord, color, visu->menu_font, "normal");
}

static char *poor_itoa(int nbr, char *buffer)
{
	int		i;

	i = 0;
	if (nbr < 0)
	{
		buffer[0] = '-';
		nbr = -nbr;
		i++;
	}
	if (nbr == 0)
		return ("0");
	while (nbr > 0)
	{
		buffer[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static void draw_player(t_visu *visu, t_vect *coord_base,
											t_vect	*menu_size, t_bushi *player)
{
	char		buffer[12];
	t_vect		size;
	t_vect		coord_txt;
	t_vect		coord_nbr;

	t_vect_actualize(&size, menu_size->x - visu->unit * 6, (visu->unit * 10));
	t_vect_actualize(&coord_txt, coord_base->x + visu->unit, coord_base->y + visu->unit / 2);
	t_vect_actualize(&coord_nbr, coord_base->x + menu_size->x * 0.6, coord_base->y + visu->unit / 2);
	draw_rectangle(coord_base, &size, GREY);
	draw_text(player->name, &coord_txt, visu->p_color[player->pindex], visu->menu_font, "underline");
	draw_text(poor_itoa(player->pnum, buffer), &coord_nbr, visu->p_color[player->pindex], visu->menu_font, "normal");
	t_vect_actualize(&coord_txt, coord_txt.x, coord_txt.y + visu->unit);
	t_vect_actualize(&coord_nbr, coord_nbr.x, coord_nbr.y + visu->unit);
	draw_line("live last :", &coord_txt, visu, LIGHT_GREY);
	draw_line("nb live last", &coord_nbr, visu, LIGHT_GREY);
	draw_line("live total :", &coord_txt, visu, LIGHT_GREY);
	draw_line("nb live total", &coord_nbr, visu, LIGHT_GREY);
	draw_line("nb_process :", &coord_txt, visu, LIGHT_GREY);
	draw_line("nb nb_process", &coord_nbr, visu, LIGHT_GREY);
	t_vect_actualize(coord_base, coord_base->x, coord_base->y + visu->unit * 8);
}

void draw_players(t_sen *core, t_visu *visu, int cycles)
{
	int				i;
	t_vect		coord_txt;
	t_vect		menu_size;

	t_vect_actualize(&coord_txt, get_win_size()->x * 0.7, 0);
	t_vect_actualize(&menu_size, get_win_size()->x - coord_txt.x,
											get_win_size()->y - coord_txt.y);
	draw_rectangle(&coord_txt, &menu_size, DARK_GREY);
	t_vect_actualize(&coord_txt, coord_txt.x + visu->unit, coord_txt.y +
																visu->unit);
	i = 0;
	coord_txt.x = coord_txt.x + visu->unit * 2;
	while (core->player[i].live != -2)
	{
		draw_player(visu, &coord_txt, &menu_size, &(core->player[i]));
		t_vect_actualize(&coord_txt, coord_txt.x, coord_txt.y +	visu->unit * 3);
		i++;
	}
	(void)cycles;
}

void draw_pc(t_sen *core, t_visu *visu)
{
	t_bo	*tmp;
	int		pos;
	int		i;
	int		j;
	t_vect	coord;
	t_vect	size;

	size.x = (visu->unit) * visu->zoom;
	size.y = visu->unit * visu->zoom;
	tmp = core->proc;
	while (tmp != NULL)
	{
		j = tmp->pc / visu->tab_size->y;
		i = tmp->pc - (j * visu->tab_size->x);
		coord.x = (visu->base_pos->x + (i * (visu->unit + visu->space)) + visu->space / 2) * visu->zoom;
		coord.y = (visu->base_pos->y + (j * (visu->unit + visu->space)) + visu->space / 2) * visu->zoom;
		if (coord.x + (visu->unit) * visu->zoom >= 0 && coord.x < get_win_size()->x && coord.y + visu->unit * visu->zoom >= 0 && coord.y < get_win_size()->y)
		{
			pos = i + (j * visu->tab_size->x);
			draw_border_rectangle(&coord, &size, visu->p_color[(int)(visu->index[pos])] + 1);
			coord.x = coord.x + ((visu->unit / 2) * visu->zoom);
			coord.y = coord.y + ((visu->unit / 2) * visu->zoom);
			draw_centred_SDLTexture(visu->texture_list[ft_abs(visu->field[pos])], &coord, 0);
		}
		tmp = tmp->next;
	}
}

void draw_core(t_visu *core)
{
	int			i;
	int 		j;
	int			pos;
	t_vect	coord;
	t_vect	size;

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
			if (coord.x + (core->unit * 2) * core->zoom >= 0 && coord.x < get_win_size()->x && coord.y + core->unit * core->zoom >= 0 && coord.y < get_win_size()->y)
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
