#include "pipex_bonus.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void		remove_here_doc(void)
{
	char		*command;
	char *const	argv[4] = {"rm", "-f", "./here_doc", 0};
	char *const	envp[1] = {0};

	command = "/bin/rm";
	if (fork() == 0)
		execve(command, argv, envp);
	else
		return ;
	exit(1);
}

void			here_doc(char **av)
{
	int		fd;
	char	*buf;

	fd = open("./here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(1, "heredoc> ", 9);
	while (get_next_line(1, &buf) > 0)
	{
		if (ft_strcmp(buf, av[2]) == 0)
			break ;
		write(1, "heredoc> ", 9);
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
	}
	close(fd);
	redirect_in("./here_doc");
	remove_here_doc();
}
