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

int				g_typo_tab[NB_COLOR];

void			set_typo_tab(void)
{
	g_typo_tab[0] = 0;
	g_typo_tab[1] = TTF_STYLE_BOLD;
	g_typo_tab[2] = TTF_STYLE_ITALIC;
	g_typo_tab[3] = TTF_STYLE_UNDERLINE;
	g_typo_tab[4] = TTF_STYLE_STRIKETHROUGH;
}

int				get_typo(int typo)
{
	return (g_typo_tab[typo]);
}
