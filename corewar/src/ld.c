void corewar_ld(t_sen *arena, t_bushi *actual, t_arg *arg_list)
{
	if (!(arg_list[0] && arg_list[1]))
	{
		if (actual != NULL)
			actual->carry = 0;
		return ;
	}
	*arg_list[1]->data = 
}
