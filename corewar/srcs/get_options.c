/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:33:54 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/11 16:51:39 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
		else if (ft_strchr("isvw", (*argv)[i][1]))
		{
			core->opt |= (1 << (int)((*argv)[i][1] - 'a'));
			i++;
		}
		else
			return (-1);
	}
	*argv += i;
	return ((*argc -= i));
}
