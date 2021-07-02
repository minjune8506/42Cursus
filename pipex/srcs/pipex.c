/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:49:14 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/02 09:49:15 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
** ./pipex file1 cmd1 cmd2 file2
** < file1 cmd1 | cmd2 > file2
*/

static void		child_process(char **av, int fd[], t_cmd *cmd)
{
	redirect_in(av[1]);
	pipe_connect(fd, STDOUT_FILENO);
	exec_cmd(cmd, av[2]);
}

static void		parent_process(char **av, int fd[], t_cmd *cmd)
{
	pipe_connect(fd, STDIN_FILENO);
	exec_cmd(cmd, av[3]);
}

static void		pipex(int ac, char **av)
{
	int		fd[2];
	int		status;
	pid_t	pid;
	t_cmd	cmd;

	if (pipe(fd) == -1)
	{
		perror("pipe error");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		exit(1);
	}
	else if (pid == 0)
		child_process(av, fd, &cmd);
	else if (pid > 0)
	{
		redirect_out(av[ac - 1]);
		waitpid(pid, &status, 0);
		parent_process(av, fd, &cmd);
	}
}

int				main(int ac, char **av)
{
	if (ac != 5)
	{
		write(2, "parameter error\n", 16);
		exit(1);
	}
	else
		pipex(ac, av);
	return (0);
}
