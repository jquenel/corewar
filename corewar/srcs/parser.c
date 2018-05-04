/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:19:52 by jquenel           #+#    #+#             */
/*   Updated: 2018/05/04 16:19:53 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_player(t_bushi *player)
{
	int	i;

	i = MAX_PLAYERS + 1;
	while (i--)
	{
		player[i].pnum = 0;
		player[i].live = -2;
		ft_memset(player[i].name, 0, PROG_NAME_LENGTH + 1);
	}
}

static void	init_state(t_sumego *state)
{
	state->c_count = 0;
	state->c_total = 0;
	state->c_todie = CYCLE_TO_DIE;
	state->c_delta = CYCLE_DELTA;
	state->l_count = 0;
	state->l_checks = 0;
	state->l_checks_limit = MAX_CHECKS;
	state->l_limit = NBR_LIVE;
	state->dump_limit = -1;
	state->l_last = TRACE_EMPTY;
}

static void	init_core(t_sen *core)
{
	core->arena.size = MEM_SIZE;
	core->pcount = 0;
	core->proc = NULL;
	core->opt = 0;
	core->visu.pause = 0;
	ft_memset(core->arena.field, 0, MEM_SIZE);
	core->arena.empty_char = TRACE_EMPTY;
	ft_memset(core->arena.trace, TRACE_EMPTY, MEM_SIZE);
	init_state(&core->state);
	init_player(core->player);
}

static int	check_valid_define(void)
{
	if (MAX_ARG_SIZE < REG_SIZE || MAX_ARG_SIZE < DIR_SIZE
		|| MAX_ARG_SIZE < IND_SIZE || MAX_ARG_SIZE > sizeof(int)
		|| REG_CODE != 1 || DIR_CODE != 2 || IND_CODE != 3
		|| MAX_ARGS_NUMBER > 4 || MAX_PLAYERS > (MEM_SIZE / CHAMP_MAX_SIZE)
		|| MAX_PLAYERS < 2 || MEM_SIZE < 1024
		|| CHAMP_MAX_SIZE > (MEM_SIZE / MAX_PLAYERS)
		|| CHAMP_MAX_SIZE < 200 || COMMENT_CHAR != '#'
		|| LABEL_CHAR != ':' || DIRECT_CHAR != '%' || SEPARATOR_CHAR != ','
		|| ft_strcmp(LABEL_CHARS, "abcdefghijklmnopqrstuvwxyz_0123456789")
		|| ft_strcmp(NAME_CMD_STRING, ".name")
		|| ft_strcmp(COMMENT_CMD_STRING, ".comment")
		|| REG_NUMBER != 16 || CYCLE_TO_DIE > 10000 || CYCLE_TO_DIE < 1000
		|| CYCLE_DELTA < 10 || CYCLE_DELTA > (CYCLE_TO_DIE / 10)
		|| NBR_LIVE < 10 || NBR_LIVE > 50 || MAX_CHECKS < 5
		|| MAX_CHECKS > 20 || T_REG != 1 || T_DIR != 2 || T_IND != 4
		|| T_LAB != 8 || PROG_NAME_LENGTH != 128
		|| COMMENT_LENGTH != 2048 || COREWAR_EXEC_MAGIC != 0xf383ea00)
	{
		ft_printf("op.h file was corrupted or badly edited.\n");
		return (0);
	}
	return (1);
}

int		parser(int argc, char **argv, t_sen *core)
{
	int	i;

	if (!check_valid_define())
		return (1);
	init_core(core);
	if (get_options(&argc, &argv, core) < 0)
		return (-1);
	if ((core->pcount = count_players(argc, argv)) < 2)
		return (1);
	i = 0;
	while (i < core->pcount)
	{
		if (create_player(&argc, &argv, core, i) == -1)
			return (1);
		i++;
	}
	return (0);
}
