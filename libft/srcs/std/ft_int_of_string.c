/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_of_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:47:35 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/01 18:02:12 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_std.h"

int	ft_int_of_string(const char *str, int *result)
{
	return (ft_int_of_string_base(str, 10, result));
}
