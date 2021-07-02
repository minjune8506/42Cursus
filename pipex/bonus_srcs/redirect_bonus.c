/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:50:12 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/02 09:50:13 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	redirect_in(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2 error");
		exit(1);
	}
	if (close(fd) == -1)
	{
		perror("close error");
		exit(1);
	}
}

void	redirect_out(const char *file, char **av)
{
	int fd;

	if (ft_strcmp(av[1], "here_doc") == 0)
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 error");
		exit(1);
	}
	if (close(fd) == -1)
	{
		perror("close error");
		exit(1);
	}
}

void	pipe_connect(int fd[2], int stdio)
{
	if (dup2(fd[stdio], stdio) == -1)
	{
		perror("dup2 error");
		exit(1);
	}
	if (close(fd[0]) == -1)
	{
		perror("close error");
		exit(1);
	}
	if (close(fd[1]) == -1)
	{
		perror("close error");
		exit(1);
	}
}
