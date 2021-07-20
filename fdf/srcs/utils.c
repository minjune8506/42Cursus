/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:25:18 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/20 15:25:19 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

char
	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, s1_len);
	free(s1);
	ft_memcpy(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	return (ret);
}

static int
	find_base(char target)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	while (base[i] != '\0')
	{
		if (ft_tolower(target) == base[i])
			return (i);
		i++;
	}
	return (-1);
}

unsigned int
	ft_atoi_base(char *nbr)
{
	unsigned int	result;

	result = 0;
	while (find_base(*nbr) != -1 && *nbr)
	{
		result *= 16;
		result += find_base(*nbr);
		nbr++;
	}
	return (result);
}

void
	print_error(char *error)
{
	if (errno == 0)
	{
		ft_putstr_fd(error, 2);
		write(2, "\n", 1);
	}
	else
		perror(error);
	exit(1);
}
