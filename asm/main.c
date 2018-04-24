/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:47:59 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/25 19:25:07 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stddef.h>
#include "parser.h"

int	main(int argc, char *argv[])
{
	if (argc > 1)
		ft_printf("Parser returned %d\n", parse(argv[1], NULL));
	return (0);
}
