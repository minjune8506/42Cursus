/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjune <minjkim2@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:04:53 by minjune           #+#    #+#             */
/*   Updated: 2021/05/21 09:10:22 by minjune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	check_newline(char *store)
{
	while (*store)
	{
		if (*store == '\n')
			return (1);
		store++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char	temp[BUFFER_SIZE];
	char	*store;

	if (read(fd, temp, BUFFER_SIZE) > 0)
	{
		while (temp)
			*store++ = *temp++;
		if (check_newline(store))

	}
	printf("line : %s", buf);
	return (0);
}

int	main(void)
{
	char	**line;
	int	fd;

	fd = open("./test", O_RDONLY);
	printf("fd : %d\n", fd);
	get_next_line(fd, line); 
}
