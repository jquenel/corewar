/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:30:46 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/06 15:31:12 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		count_players(int argc, char **argv)
{
	int	i;
	int	pc;

	i = 0;
	pc = 0;
	while (i < argc)
	{
		if ((ft_strcmp(argv[i], "-n")))
		{
			if (argv[i][0] == '-')
				return (-1);
		}
		else
		{
			if (++i >= argc || (!is_all_nums(argv[i])
					&& !(argv[i][0] == '-' && is_all_nums(&(argv[i][1])))))
				return (-1);
			if (++i >= argc || argv[i][0] == '-')
				return (-1);
		}
		if (++pc > MAX_PLAYERS)
			return (-1);
		i++;
	}
	return (pc);
}
