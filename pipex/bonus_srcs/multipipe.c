/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:49:56 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/02 09:49:57 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	multi_pipe(int cmd_count, char **av, int fd[], t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	pipe(fd);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		pipe_connect(fd, 0);
	}
	else if (pid == 0)
	{
		pipe_connect(fd, 1);
		exec_cmd(cmd, av[cmd_count]);
	}
}
