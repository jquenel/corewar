#include "corewar.h"

void		init_optab(t_optab op[OP_COUNT + 1])
{
	op[0] = (t_optab){corewar_live, 1, {T_DIR}, 10, 0};
	op[1] = (t_optab){corewar_ld, 2, {T_DIR | T_IND, T_REG}, 5, EX_CD};
	op[2] = (t_optab){corewar_st, 2, {T_REG, T_IND | T_REG}, 5, EX_CD};
	op[3] = (t_optab){corewar_add, 3, {T_REG, T_REG, T_REG}, 10, EX_CD};
	op[4] = (t_optab){corewar_sub, 3, {T_REG, T_REG, T_REG}, 10, EX_CD};
	op[5] = (t_optab){corewar_and, 3,
		{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, EX_CD};
	op[6] = (t_optab){corewar_or, 3,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, EX_CD};
	op[7] = (t_optab){corewar_xor, 3,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6, EX_CD};
	op[8] = (t_optab){corewar_zjmp, 1, {T_DIR}, 20, EX_IS};
	op[9] = (t_optab){corewar_ldi, 3,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 25, EX_CD | EX_IS};
	op[10] = (t_optab){corewar_sti, 3,
		{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 25, EX_CD | EX_IS};
	op[11] = (t_optab){corewar_fork, 1, {T_DIR}, 800, EX_IS};
	op[12] = (t_optab){corewar_lld, 2, {T_DIR | T_IND, T_REG}, 10, EX_CD};
	op[13] = (t_optab){corewar_lldi, 3,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 50, EX_CD | EX_IS};
	op[14] = (t_optab){corewar_lfork, 1, {T_DIR}, 1000, EX_IS};
	op[15] = (t_optab){corewar_aff, 1, {T_REG}, 1, EX_CD};
	op[16] = (t_optab){NULL, 0, {0}, 0, 0};
}
