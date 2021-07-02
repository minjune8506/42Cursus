/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:48:51 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/02 09:48:52 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	parse_cmd(char *str, t_cmd *cmd)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	cmd->cmd[0] = ft_strjoin("/bin/", tmp[0]);
	cmd->cmd[1] = ft_strjoin("/usr/bin/", tmp[0]);
	cmd->cmd[2] = ft_strjoin("/usr/local/bin/", tmp[0]);
	cmd->cmd[3] = ft_strjoin("/usr/sbin/", tmp[0]);
	cmd->cmd[4] = ft_strjoin("/sbin/", tmp[0]);
	cmd->argv = tmp;
	cmd->envp = NULL;
}

void		exec_cmd(t_cmd *cmd, char *str)
{
	int i;

	i = 0;
	parse_cmd(str, cmd);
	while (i < 5)
	{
		execve(cmd->cmd[i], cmd->argv, cmd->envp);
		i++;
	}
	perror("execve error");
	exit(1);
}
