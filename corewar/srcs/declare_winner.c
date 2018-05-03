#include "corewar.h"

void		declare_winner(t_sen *core, int alive)
{
	int		i;

	if (!alive)
	{
		if (core->state.l_last == core->arena.empty_char)
			ft_printf("No winner today !\n\
Next time, try using REAL champions ?\n");
		else
		{
			i = 0;
			while (core->player[i].pnum != core->state.l_last)
				i++;
			ft_printf("Player %d(%s) won !\n", core->player[i].pnum,
				core->player[i].name);
		}
	}
	else
	{
		i = 0;
		while (core->player[i].live < 0)
			i++;
		ft_printf("Player %d(%s) won !\n", core->player[i].pnum,
				core->player[i].name);
	}
}
