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
	else if (str[format->index] == '*')
	{
		format->width = va_arg(format->ap, int);
		if (format->width < 0)
		{
			format->flag = 1;
			format->width *= -1;
		}
		format->index++;
	}
}
