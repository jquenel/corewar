void corewar_live(t_sen *arena, t_bushi *actual, t_arg *arg_list)
{
	t_bushi *player;
	int		nb_player;

	if (arg_list[0] == NULL || arg[0]->type != 2)
		return ;
	nb_player = (int)(arg_list[0]->data);
	player = arena->player
	while (nb_player-- && player != NULL)
		player = player->next;
	if (player != NULL)
		ft_printf("le joueur %d(%s) est en vie\n", player->pnum, player->name);
}
