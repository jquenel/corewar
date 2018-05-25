/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:47:59 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/24 16:31:52 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft_list.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "ast.h"
#include "compile.h"
#include "op.h"
#include "parser.h"
#include "semantics.h"
#include "xmalloc.h"

int	main(int argc, char *argv[])
{
	t_ast		ast;
	t_hashtable *labels_hashtable;
	size_t		prog_size;
	int			ret;

	if (argc == 1)
	{
		ft_dprintf(STDERR_FILENO, "No assembly file specified as argument.\n");
		return (1);
	}
	init_ast(&ast);
	if ((ret = parse(argv[1], &ast)))
	{
		ft_list_reverse((t_list **)&ast.elements);
		labels_hashtable =
			ft_hashtable_make(ft_hashfun_string, ft_compfun_string, 8);
		if (labels_hashtable == NULL)
			die_oom();
		if ((ret = check_semantics(&ast, labels_hashtable, &prog_size)))
			ret = compile(&ast, labels_hashtable, argv[1], prog_size);
		ft_hashtable_destroy(labels_hashtable, free);
	}
	destroy_ast(&ast);
	return (!ret);
}
