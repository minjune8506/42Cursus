#include <string.h>
#include <stdio.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	if (ac != 5)
		write(2, "error\n", 6);
		exit();
}