/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:47:59 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/29 01:36:07 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stddef.h>
#include "ast.h"
#include "parser.h"

int	main(int argc, char *argv[])
{
	t_ast	ast;

	if (argc == 1)
		return (1);
	ast.elements = NULL;
	if (!parse(argv[1], &ast))
		return (1);
	return (0);
}
