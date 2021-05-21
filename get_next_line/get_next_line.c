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
	return (-1);
}

int	sep_line(char **line, char **store, int new_line)
{
	char	*temp;

	(*store)[new_line] = 0;
	*line = ft_strdup(*store);
	temp = ft_strdup(*store + new_line + 1);
	free(*store);
	*store = temp;
	return (1);	
}

int remain_content(char **line, char **store, int read_size)
{
	if (read_size < 0)
		return (-1);
	else if (*store)
	{
		*line = *store;
		*store = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*store[OPEN_MAX];
	int			new_line;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		store[fd] = ft_strjoin(store[fd], buff);
		if ((new_line = check_newline(store[fd])) > 0)
			return (sep_line(line, &store[fd], new_line));
	}
	return (remain_content(line, &store[fd], read_size));
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
	printf("line : %s\n", line);
	printf("ret : %d\n", ret);
	close(fd);
	return (0);
}