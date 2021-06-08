/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:52:52 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/08 19:52:53 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format(t_format *format)
{
	format->per = 0;
	format->flag = 0;
	format->width = 0;
	format->dot = 0;
	format->precision = -1;
	format->index = 0;
	format->ret = 0;
}

void	get_format(t_format *format, const char *str)
{
	get_per(format, str);
	get_flag(format, str);
	get_width(format, str);
	get_prec(format, str);
}

#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	t_format format;

	va_start(format.ap, str);
	init_format(&format);
	while (str[format.index])
	{
		get_format(&format, str);
		if (str[format.index] == 'c')
			type_c(&format);
	}
	// printf("format->per : %d\n", format.per);
	// printf("format->flag : %d\n", format.flag);
	// printf("format->width : %d\n", format.width);
	// printf("format->dot : %d\n", format.dot);
	// printf("format->precision : %d\n", format.precision);
	// printf("format->ret : %d\n", format.ret);
	return (format.ret);
}

// 	int	main(void)
// 	{
// 		ft_printf("-->|%-4.c|<--\n", -135);
// 		ft_printf("-->|%-4.c|<--\n", -1);
// 		ft_printf("-->|%-4.c|<--\n", 0);
// 		ft_printf("-->|%-4.c|<--\n", 1);
// 		ft_printf("-->|%-4.c|<--\n", 13);
// 		ft_printf("-->|%-4.c|<--\n", 198);
// 		printf("---------\n");
// 		printf("-->|%-4.c|<--\n", -135);
// 		printf("-->|%-4.c|<--\n", -1);
// 		printf("-->|%-4.c|<--\n", 0);
// 		printf("-->|%-4.c|<--\n", 1);
// 		printf("-->|%-4.c|<--\n", 13);
// 		printf("-->|%-4.c|<--\n", 198);
		
// 	}