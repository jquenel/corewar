/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:47:59 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/10 00:05:54 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stddef.h>
#include <unistd.h>
#include "ast.h"
#include "compile.h"
#include "op.h"
#include "parser.h"
#include "semantics.h"

int	main(int argc, char *argv[])
{
	t_ast		ast;
	t_hashtable *labels_hashtable;
	size_t		prog_size;

	if (argc == 1)
		return (1);
	ast.elements = NULL;
	if (!parse(argv[1], &ast))
	{
		ft_dprintf(STDERR_FILENO, "Syntax error.\n");
		return (1);
	}
	if (!check_semantics(&ast, &labels_hashtable, &prog_size))
		return (1);
	compile(&ast, labels_hashtable, argv[1], prog_size);
	return (0);
}
