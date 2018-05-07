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

t_typo			*set_t_typo(t_typo *v_font, char *typo, int color_type,
																TTF_Font *font)
{
	v_font->typo = typo;
	v_font->color_type = color_type;
	v_font->font = font;
	return (v_font);
}
