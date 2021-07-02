/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:49:48 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/02 09:49:48 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void		remove_here_doc(void)
{
	char		*command;
	char *const	argv[4] = {"rm", "-f", "./here_doc", 0};
	char *const	envp[1] = {0};
	pid_t		pid;

	command = "/bin/rm";
	pid = fork();
	if (pid == 0)
		execve(command, argv, envp);
	else if (pid > 0)
		return ;
	else if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
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
