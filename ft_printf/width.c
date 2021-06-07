/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:05:09 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/07 15:05:10 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (*s == (char)c)
		return (1);
	return (0);
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

void	check_width(const char *str, t_format *format)
{
	if (!ft_strchr("cspduxX%", str[format->index] && is_digit(str, format)))
	{
		format->width = ft_atoi(str, format);
	}
}
