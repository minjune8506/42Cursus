#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// ./pipex file1 cmd1 cmd2 file2

int main(int ac, char **av)
{
	int fd[2];
	int pid;
	char *infile;
	char *outfile;

	if (ac != 5)
	{
		write(2, "parameter error\n", 6);
		exit(1);
	}
	else
	{
		infile = av[1];
		outfile = av[ac - 1];
		// infile, outfile 권한 check (access)
		// infile : read
		// outfile : write

		if (pipe(fd) < 0)
		{
			write(2, "pipe error\n", 6);
			exit(1);
		}
		pid = fork();
		if (pid < 0)
		{
			write(2, "fork error\n", 6);
			exit(1);
		}
		if (pid == 0)
			child_process();
		else
			parents_process();
	}
}