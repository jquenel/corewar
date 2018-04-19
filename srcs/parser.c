#include "corewar.h"

static void	init_player(t_bushi *player)
{
	int	i;

	i = MAX_PLAYERS;
	while (i--)
	{
		player[i].pnum = 0;
		player[i].carry = 0;
		player[i].live = 0;
		ft_bzero(player[i].reg, REG_NUMBER + 1);
		ft_bzero(player[i].name, PROG_NAME_LENGTH + 1);
	}
}

static void	init_state(t_sumego *state)
{
	state->c_count = 0;
	state->c_total = 0;
	state->c_todie = CYCLE_TO_DIE;
	state->c_delta = CYCLE_DELTA;
	state->l_count = 0;
	state->l_count = 0;
	state->l_checks = 0;
	state->l_limit = MAX_CHECKS;
	state->dump_limit = -1;
}

static int	init_core(t_sen *core)
{
	core->arena.size = MEM_SIZE;
	ft_bzero(&core->arena.field, MEM_SIZE);
	init_state(&core->state);
	init_player(&core->player);
}

static int	check_valid_define(void)
{
	return (1);
}

int		parser(int argc, char **argv, t_sen *core)
{
	int	i;
	int	pc;

	if (!check_valid_define())
		return (1);
	init_core(core);
	get_options(&argc, &argv, core);
	if ((pc = count_players(argc, argv)) < 2)
		return (1);
	while (i < pc)
	{
		if (create_player(&argc, &argv, core, pc) == -1)
			return (1);
		i--;
	}
	return (0);
}
