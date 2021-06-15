/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:37:20 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/21 21:35:14 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#define FD_MAX 256

static int	check_newline(char *buff)
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

static int	sep_line(char **line, char **store, int new_line)
{
	char	*temp;

	(*store)[new_line] = '\0';
	if (!(*line = ft_strdup(*store)))
		return (-1);
	if (!(temp = ft_strdup(*store + new_line + 1)))
		return (-1);
	free(*store);
	*store = temp;
	return (1);
}

static int	remain_content(char **line, char **store, int read_size)
{
	int i;

	if (read_size < 0)
	{
		if (*store)
			free(*store);
		return (-1);
	}
	if (*store && (i = check_newline(*store)) >= 0)
		return (sep_line(line, store, i));
	else if (*store)
	{
		*line = *store;
		*store = NULL;
		return (0);
	}
	if (!(*line = ft_strdup("")))
		return (-1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*store[FD_MAX];
	int			new_line;
	int			read_size;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || !line || (FD_MAX <= fd))
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_size] = '\0';
		if (!(store[fd] = ft_strjoin(store[fd], buff)))
			return (-1);
		new_line = check_newline(store[fd]);
		if (new_line >= 0)
		{
			free(buff);
			return (sep_line(line, &store[fd], new_line));
		}
	}
	free(buff);
	return (remain_content(line, &store[fd], read_size));
}
