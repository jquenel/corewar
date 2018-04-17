/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:07:18 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/10 16:30:21 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char				*ft_itoa(int n)
{
	char	*result;
	size_t	len;

	len = digits(n < 0 ? -n : n);
	result = (char *)malloc(sizeof(*result) * (len + 1 + (n < 0)));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		*result = '-';
		put(result + 1, -n, len);
	}
	else
		put(result, n, len);
	return (result);
}
