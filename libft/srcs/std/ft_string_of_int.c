/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_of_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:08:56 by sboilard          #+#    #+#             */
/*   Updated: 2018/03/01 18:57:58 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_std.h"

int	ft_string_of_int(int number, char **result)
{
	*result = ft_itoa(number);
	return (*result != NULL);
}
