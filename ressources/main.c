#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_WRONLY | O_CREAT);
	int	i = 12;
	int	j = 3;

	while (j >= 0)
	{
		write(fd, &(((char *)&i)[j]), 1);
		printf("%hhd\n", (((char *)&i)[j]));
		j--;
	}
	return (0);
}
