/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:12:26 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 15:27:26 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_str.h>

int	ft_strisstr(const char *str, const char *ref)
{
	unsigned char	tab[256 / 8];
	unsigned char	c;

	ft_memset(tab, 0, sizeof(tab));
	while ((c = *ref) != '\0')
	{
		tab[c / 8] |= 1 << c % 8;
		++ref;
	}
	while ((c = *str++) != '\0')
		if (!(tab[c / 8] >> c % 8 & 1))
			return (0);
	return (1);
}
