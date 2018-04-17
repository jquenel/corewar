/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:35:06 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/19 19:50:04 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_io.h"

static unsigned int	digits(unsigned int nb)
{
	unsigned int	result;

	result = 1;
	while (nb >= 10)
	{
		++result;
		nb /= 10;
	}
	return (result);
}

static void			put(char *s, unsigned int n, size_t len)
{
	size_t	i;

	s[len] = '\0';
	i = 1;
	while (i <= len)
	{
		s[len - i] = n % 10 + '0';
		n /= 10;
		++i;
	}
}

void				ft_putnbr(int n)
{
	char	result[12];
	size_t	len;

	len = digits(n < 0 ? -n : n);
	if (n < 0)
	{
		*result = '-';
		put(result + 1, -n, len);
	}
	else
		put(result, n, len);
	ft_putstr(result);
}
