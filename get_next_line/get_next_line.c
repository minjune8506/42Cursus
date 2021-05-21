/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:37:20 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/21 14:37:23 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int check_newline(char *buff)
{
	int index;

	index = 0;
	while (buff[index])
	{
		if (buff[index] == '\n')
			return (index);
		index++;
	}
	return (0);
}

int	*sep_line(char *store, int new_line)
{
	char	*temp;

	temp = store + new_line + 1;
	// printf("sep_line : %s\n", temp);
	free(store);
	store = temp;
	return (0);
}

int get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*store[OPEN_MAX];
	int			new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		store[fd] = ft_strjoin(store[fd], buff);
		// printf("store[%d] : %s\n", fd, store[fd]);
		if ((new_line = check_newline(store[fd])))
		{
			*line = ft_substr(store[fd], 0, new_line);
			// printf("*line : %s\n", *line);
			sep_line(store[fd], new_line);
			return (1);
		}
	}
	return (0);
}

int main(void)
{
	char *line;
	int fd;
	int ret;
	fd = open("./test2", O_RDONLY);
	while ((ret = (get_next_line(fd, &line))) > 0)
	{
		printf("line : %s\n", line);
		printf("ret : %d\n", ret);
	}
	close(fd);
	return (0);
}
