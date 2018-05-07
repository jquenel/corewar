#include "template.h"
#include "corewar.h"

void set_texture_list(t_visu *visu)
{
	int			i;
	char		*text;
	SDL_Surface	*surface;

	if (visu->font != NULL)
		TTF_CloseFont(visu->font);
	visu->font_size = (visu->unit / 1.8) * visu->zoom;
	visu->font = TTF_OpenFont(FONT_PATH, visu->font_size);
	i = 0;
	while (i < 256)
	{
		text = ft_itoa_base(i, "0123456789abcdef");
		if (ft_strlen(text) < 2)
			ft_stradd_front("0", &text);
		surface = TTF_RenderText_Blended(visu->font, text, get_color(BLACK));
		visu->texture_list[i] = SDL_CreateTextureFromSurface(get_renderer(), surface);
		SDL_FreeSurface(surface);
		free(text);
		i++;
	}
}

static void draw_line(char *text, t_vect *coord, t_visu *visu,
																	int color)
{
	draw_text(text, coord, color, visu->menu_font, "normal");
	t_vect_actualize(coord, coord->x, coord->y + visu->unit * 2);
}

static int		ft_intlen(intmax_t nbr)
{
	int		size;

	if (nbr == 0)
		return (1);
	size = 0;
	if (nbr < 0)
	{
		size++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size++);
}

static char *poor_itoa(int nbr, char *buffer)
{
	int		i;
	int		negative;
	int		len;

	i = 0;
	len = ft_intlen(nbr);
	buffer[len] = '\0';
	len--;
	negative = 0;
	if (nbr < 0)
	{
		buffer[0] = '-';
		negative = 1;
	}
	while (len >= negative)
	{
		buffer[len] = ((nbr % 10) >= 0 ? (nbr % 10) : (nbr % 10) * -1) + '0';
		len--;
		nbr /= 10;
	}
	return (buffer);
}

static void draw_player(t_visu *visu, t_vect *base,	t_vect	*menu_size, t_bushi *player)
{
	char		buffer[12];
	t_vect		size;
	t_vect		txt;
	t_vect		nbr;

	t_vect_actualize(&size, menu_size->x - visu->unit * 6, (visu->unit * 10));
	t_vect_actualize(&txt, base->x + visu->unit, base->y + visu->unit / 2);
	t_vect_actualize(&nbr, base->x + menu_size->x * 0.6, base->y + visu->unit / 2);
	draw_rectangle(base, &size, GREY);
	draw_text(player->name, &txt, visu->p_color[player->pindex], visu->menu_font, "underline");
	draw_text(poor_itoa(player->pnum, buffer), &nbr, visu->p_color[player->pindex], visu->menu_font, "normal");
	t_vect_actualize(&txt, txt.x, txt.y + visu->unit);
	t_vect_actualize(&nbr, nbr.x, nbr.y + visu->unit);
	t_vect_actualize(&txt, txt.x, txt.y + visu->unit * 2);
	t_vect_actualize(&nbr, nbr.x, nbr.y + visu->unit * 2);
	draw_line("live last :", &txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(player->live_last, buffer), &nbr, visu, LIGHT_GREY);
	draw_line("live this period :", &txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(player->live, buffer), &nbr, visu, LIGHT_GREY);
	draw_line("nb_process :", &txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(player->proc_count, buffer), &nbr, visu, LIGHT_GREY);
	t_vect_actualize(base, base->x, base->y + visu->unit * 8);
}

static void		draw_cycles(t_sen *core, t_visu *visu, t_vect *txt,	t_vect	*menu_size)
{
	char		buffer[25];
	t_vect		nbr1;
	t_vect		nbr2;
	t_vect		nbr3;

	t_vect_actualize(&nbr1, txt->x + menu_size->x * 0.6, txt->y);
	t_vect_actualize(&nbr2, txt->x + menu_size->x * 0.7, txt->y + visu->unit * 2);
	t_vect_actualize(&nbr3, txt->x + menu_size->x * 0.75, txt->y + visu->unit * 2);
	draw_line("Cycles : ", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(core->state.c_total, buffer), &nbr1, visu, LIGHT_GREY);
	draw_line("Period : ", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(core->state.c_count, buffer), &nbr1, visu, LIGHT_GREY);
	draw_line(" / ", &nbr2, visu, LIGHT_GREY);
	draw_line(poor_itoa(core->state.c_todie, buffer), &nbr3, visu, LIGHT_GREY);
	draw_line("Cycles per second : ", txt, visu, LIGHT_GREY);
	draw_line(poor_itoa(get_fps(), buffer), &nbr1, visu, LIGHT_GREY);
}

void draw_info(t_sen *core, t_visu *visu)
{
	t_vect	mpos;
	t_vect	size;
	t_vect	coord;
	int		pos;
	char	c;

	SDL_GetMouseState(&(mpos.x), &(mpos.y));
	size.x = visu->unit * 15;
	size.y = visu->unit * 2;
	coord.x = (mpos.x - (visu->base_pos->x * visu->zoom)) /
									((visu->unit + visu->space) * visu->zoom);
	coord.y = (mpos.y - (visu->base_pos->y * visu->zoom)) /
									((visu->unit + visu->space) * visu->zoom);
	pos = (coord.x + (coord.y * visu->tab_size->x));
	if (pos >= 0 && pos < MEM_SIZE)
	{
		c = core->arena.field[pos];
		if (c < OP_COUNT && c > 0)
		{
			t_vect_actualize(&mpos, mpos.x + visu->unit, mpos.y + visu->unit);
			draw_border_rectangle(&mpos, &size, GREY);
			t_vect_actualize(&mpos, mpos.x + size.x / 2, mpos.y + size.y / 2);
			draw_centred_text(visu->str_list[(int)c - 1], &mpos, BLACK, visu->menu_font, "normal");
		}
	}

}

void draw_menu(t_sen *core, t_visu *visu, int cycles)
{
	int			i;
	t_vect		txt;
	t_vect		menu_size;

	t_vect_actualize(&txt, get_win_size()->x * 0.7, 0);
	t_vect_actualize(&menu_size, get_win_size()->x - txt.x,
													get_win_size()->y - txt.y);
	draw_rectangle(&txt, &menu_size, DARK_GREY);
	t_vect_actualize(&txt, txt.x + visu->unit, txt.y + visu->unit);
	draw_cycles(core, visu, &txt, &menu_size);
	i = 0;
	while (core->player[i].live != -2)
	{
		draw_player(visu, &txt, &menu_size, &(core->player[i]));
		t_vect_actualize(&txt, txt.x, txt.y + visu->unit * 3);
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

	t_vect_actualize(&size, (visu->unit) * visu->zoom, visu->unit * visu->zoom);
	tmp = core->proc;
	while (tmp != NULL)
	{
		j = tmp->pc / visu->tab_size->y;
		i = tmp->pc - (j * visu->tab_size->x);
		coord.x = (visu->base_pos->x + (i * (visu->unit + visu->space)) + visu->space / 2) * visu->zoom;
		coord.y = (visu->base_pos->y + (j * (visu->unit + visu->space)) + visu->space / 2) * visu->zoom;
		if (coord.x + (visu->unit) * visu->zoom >= 0 && coord.x <
			get_win_size()->x && coord.y + visu->unit * visu->zoom >= 0 &&
			coord.y < get_win_size()->y)
		{
			pos = i + (j * visu->tab_size->x);
			draw_border_rectangle(&coord, &size, visu->p_color[(int)(visu->index[pos])] + 1);
			coord.x = coord.x + ((visu->unit / 2) * visu->zoom);
			coord.y = coord.y + ((visu->unit / 2) * visu->zoom);
			draw_centred_SDLTexture(visu->texture_list[(unsigned char)(visu->field[pos])], &coord, 0);
		}
		tmp = tmp->next;
	}
}

void draw_core(t_visu *visu)
{
	int			i;
	int 		j;
	int			pos;
	t_vect		coord;
	t_vect		size;

	SDL_SetRenderDrawColor(get_renderer(), 40, 40, 40, 255);
	SDL_RenderClear(get_renderer());
	size.x = visu->unit * visu->zoom;
	size.y = visu->unit * visu->zoom;
	i = 0;
	while (i < visu->tab_size->x)
	{
		j = 0;
		while (j < visu->tab_size->y)
		{
			coord.x = (visu->base_pos->x + (i * (visu->unit + visu->space)) + visu->space / 2) * visu->zoom;
			coord.y = (visu->base_pos->y + (j * (visu->unit + visu->space)) + visu->space / 2) * visu->zoom;
			if (coord.x + (visu->unit * 2) * visu->zoom >= 0 && coord.x < get_win_size()->x && coord.y + visu->unit * visu->zoom >= 0 && coord.y < get_win_size()->y)
			{
				pos = i + (j * visu->tab_size->x);
				draw_border_rectangle(&coord, &size, visu->p_color[(int)(visu->index[pos])]);
				coord.x = coord.x + (size.x / 2);
				coord.y = coord.y + (size.y / 2);
				draw_centred_SDLTexture(visu->texture_list[(unsigned char)(visu->field[pos])], &coord, 0);
			}
			j++;
		}
		i++;
	}
}
