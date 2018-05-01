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
	state->l_last = -1;
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
	ft_memset(core->arena.trace, core->arena.empty_char, MEM_SIZE);
	init_state(&core->state);
	init_player(core->player);
}

static int	check_valid_define(void)
{
	if (MAX_ARG_SIZE < REG_SIZE ||
		MAX_ARG_SIZE < DIR_SIZE ||
		MAX_ARG_SIZE < IND_SIZE)
		return (0);
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
