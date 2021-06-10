/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:07:50 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/08 20:07:51 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int		ft_atoi(const char *str, t_format *format)
{
	int		result;

	result = 0;
	while (str[format->index] >= '0' && str[format->index] <= '9')
	{
		result *= 10;
		result += str[format->index] - '0';
		format->index++;
	}
	return (result);
}

int		is_digit(const char *str, t_format *format)
{
	if (str[format->index] >= '0' && str[format->index] <= '9')
		return (1);
	return (0);
}

int		ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}
