#include "pipex_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void	print_error(void)
{
	perror("error");
	exit(1);
}

static void	child_process(char **av, int fd[], t_cmd *cmd)
{
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		here_doc(av);
		pipe_connect(fd, STDOUT_FILENO);
		exec_cmd(cmd, av[3]);
	}
	else
	{
		redirect_in(av[1]);
		pipe_connect(fd, STDOUT_FILENO);
		exec_cmd(cmd, av[2]);
	}
}

static void	parent_process(int ac, char **av, int fd[], t_cmd *cmd)
{
	int cmd_count;

	cmd_count = ac - 5;
	pipe_connect(fd, STDIN_FILENO);
	while ((cmd_count < ac - 2) && (ac > 6))
	{
		multi_pipe(cmd_count, av, fd, cmd);
		cmd_count++;
	}
	redirect_out(av[ac - 1], av);
	if (ft_strcmp(av[1], "here_doc") == 0)
		exec_cmd(cmd, av[4]);
	else
		exec_cmd(cmd, av[ac - 2]);
}

static void	pipex(int ac, char **av)
{
	int		fd[2];
	int		status;
	pid_t	pid;
	t_cmd	cmd;

	if (pipe(fd) == -1)
		print_error();
	pid = fork();
	if (pid < 0)
		print_error();
	else if (pid == 0)
		child_process(av, fd, &cmd);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		parent_process(ac, av, fd, &cmd);
	}
}

int			main(int ac, char **av)
{
	if (ac < 5)
	{
		write(2, "parameter error\n", 16);
		exit(1);
	}
	else
		pipex(ac, av);
	return (0);
}
