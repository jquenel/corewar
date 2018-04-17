/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:47:35 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/11 17:02:07 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

static int	read_digit(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_islower(c))
		return (c - 'a' + 10);
	else if (ft_isupper(c))
		return (c - 'A' + 10);
	else
		return (-1);
}

static void	interpret_sign(const char **str, int *positive)
{
	if (**str == '-')
	{
		*positive = 0;
		++*str;
	}
	else
	{
		*positive = 1;
		if (**str == '+')
			++*str;
	}
}

static void	interpret_base(const char **str, int *base)
{
	if (**str == '0')
	{
		++*str;
		if (**str == 'x')
		{
			++*str;
			*base = 16;
		}
		else
			*base = 8;
	}
	else
		*base = 10;
}

long		ft_atoi_base(const char *str, int base)
{
	int		positive;
	int		digit;
	long	result;

	if (base < 0 || base == 1 || base > 36)
		return (0);
	while (ft_isspace(*str))
		++str;
	interpret_sign(&str, &positive);
	if (base == 0)
		interpret_base(&str, &base);
	result = 0;
	digit = read_digit(*str);
	while (digit >= 0 && digit < base)
	{
		result = result * base + digit;
		digit = read_digit(*++str);
	}
	return (positive ? result : -result);
}
