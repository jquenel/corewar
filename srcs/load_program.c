#include "corewar.h"
#include <fcntl.h>

int		load_program(char *file, t_sen *core, t_bushi *player,
					t_bo *proc)
{
	char		buf[BUFF_SIZE + 1];
	int		fd;
	int		c;
	int		i;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	check = read(fd, buf, BUFF_SIZE);
	if (check <= 4 || *((int *)buf) != COREWAR_EXEC_MAGIC)
		return (-1);
	buf[check] = '\0';
	i = sizeof(int);
	i = get_player_name(core, player, buf, i);


}
