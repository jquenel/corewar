/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboissy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:01:15 by jboissy           #+#    #+#             */
/*   Updated: 2017/11/25 00:41:35 by jboissy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

t_tileset		*create_tileset(char *path)
{
	t_tileset *tile;
	int		file;
	char	*line;
	char	**split_line;

	file = open("path" , O_RDONLY);
	if (file == -1)
	{
		line = ft_strdup("Cant open such file : ");
		ft_stradd_back(&line, path);
		error_exit(line, 152);
	}
	line = get_strsplit(&file, ':', 2)[1];
	split_line = get_strsplit(&file, ':', 3);
	tile = initiate_tileset(line, ft_atoi(split_line[1]), ft_atoi(split_line[2]));
	return (tile);
}

static SDL_Rect *create_rect_list(int size)
{
	SDL_Rect *tmp;

	if (!(tmp = (SDL_Rect *)malloc(sizeof(SDL_Rect) * size)))
		error_exit("Can't malloc a SDL_Rect", 165);
	return (tmp);
}

void draw_tileset(t_tileset *tile, int sprite, t_2d_coord *coord, t_2d_coord *size, double angle)
{
	SDL_Rect		dstrect;
	SDL_Rect		sprite_rect;


	sprite_rect = tile->sprite_list[sprite];
	dstrect.x = coord->x - size->x / 2;
	dstrect.y = coord->y - size->y / 2;
	dstrect.w = size->x;
	dstrect.h = size->y;
	if (angle != 0)
		SDL_RenderCopyEx(get_renderer(), tile->texture, &sprite_rect, &dstrect, angle, NULL, SDL_FLIP_NONE);
	else
		SDL_RenderCopy(get_renderer(), tile->texture, &sprite_rect, &dstrect);
}

t_tileset		*initiate_tileset(char *path, int value_x, int value_y)
{
	t_tileset *this;
	int				i;
	double			ix;
	double			iy;

	if (!(this = (t_tileset *)malloc(sizeof(t_tileset))))
		error_exit("Can't malloc a tileset", 165);
	this->image = IMG_Load(path);
	if (this->image == NULL)
		error_exit("Can't open a tileset", 245);
	this->texture = SDL_CreateTextureFromSurface(get_renderer(), this->image);
	if(!(this->texture))
		error_exit("Can't draw texture", 2555);
	this->nb_tile_x = value_x;
	this->nb_tile_y = value_y;
	this->size = t_2d_coord_new(this->image->w / value_x, this->image->h / value_y);
	this->sprite_list = create_rect_list(value_x * value_y);
	i = 0;
	ix = 0;
	iy = 0;
	while (i < value_x * value_y)
	{
		if (ix >= value_x)
		{
			ix = 0;
			iy++;
		}
 		this->sprite_list[i].x = ix * this->size->x;
		this->sprite_list[i].y = iy * this->size->y;
		this->sprite_list[i].w = this->size->x;
		this->sprite_list[i].h = this->size->y;
		ix++;
		i++;
	}
	return (this);
}

int			get_sprite(t_tileset *tile, int x, int y)
{
	int result;

	result = x + (tile->nb_tile_x * y);
	if (result > tile->nb_tile_x * tile->nb_tile_y)
		return ((tile->nb_tile_x * tile->nb_tile_y) - 1);
	return (result);
}
