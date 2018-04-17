/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_of_string_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:49:58 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/13 20:25:05 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_std.h"
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

int			ft_int_of_string_base(const char *str, int base, int *result)
{
	int	positive;
	int	digit;
	int	acc;

	if (base < 0 || base == 1 || base > 36)
		return (0);
	interpret_sign(&str, &positive);
	if (base == 0)
		interpret_base(&str, &base);
	acc = 0;
	while (*str != '\0')
	{
		digit = read_digit(*str++);
		if (digit < 0 || digit >= base)
			return (0);
		acc = acc * base + digit;
	}
	if (result != NULL)
		*result = (positive ? acc : -acc);
	return (1);
}
