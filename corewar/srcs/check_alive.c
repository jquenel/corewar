#include "corewar.h"

static t_bo	*kill_proc(t_bo **proc, t_bo *dead, t_bo *prev)
{
	t_bo		*tmp;

	tmp = dead->next;
	if (dead == *proc)
		*proc = dead->next;
	else
		prev->next = dead->next;
	free(dead);
	return (tmp);
}

static int	check_alive_proc(t_bo **proc)
{
	t_bo		*tmp1;
	t_bo		*tmp2;
	int			count;

	tmp1 = *proc;
	tmp2 = NULL;
	while (tmp1)
	{
		if (tmp1->live == 0)
			tmp1 = kill_proc(proc, tmp1, tmp2);
		else
		{
			tmp2 = tmp1;
			tmp1->live = 0;
			tmp1 = tmp1->next;
		}
	}
	tmp1 = *proc;
	count = 0;
	while (tmp1)
	{
		count++;
		tmp1 = tmp1->next;
	}
	return (count);
}

int			check_alive(t_bushi *player, t_bo **proc)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (player[i].live != -2)
	{
		if (player[i].live > 0)
		{
			player[i].live = 0;
			count++;
		}
		else
			player[i].live = -1;
		i++;
	}
	if (!check_alive_proc(proc))
		return (0);
	return (count);
}


