/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:33:54 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/25 22:52:42 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	add_options(t_sen *core, char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (!ft_strchr(AVAILABLE_OPT, str[i]))
			return (0);
		core->opt |= (1 << (int)((str[i]) - 'a'));
		i++;
	}
	return (1);
}

int		get_options(int *argc, char ***argv, t_sen *core)
{
	int	i;

	i = 0;
	while (i < *argc - 1 && (*argv)[i][0] == '-'
			&& ft_strcmp((*argv)[i], "-n"))
	{
		if (!ft_strcmp((*argv)[i], "-dump"))
		{
			if (!is_all_nums((*argv)[i + 1]) ||
			!(core->state.dump_limit = ft_atoi((*argv)[i + 1])))
				return (-1);
			core->opt |= OPT_DUMP;
			i += 2;
		}
		else if (add_options(core, (*argv)[i]))
			i++;
		else
			return (-1);
	}
	*argv += i;
	return ((*argc -= i));
}
