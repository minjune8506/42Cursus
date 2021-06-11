/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:52:52 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/09 15:28:32 by minjune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_format(t_format *format)
{
	format->per = 0;
	format->width = 0;
	format->dot = 0;
	format->prec = -1;
	format->flag_minus = 0;
	format->flag_zero = 0;
	format->flag_plus = 0;
	format->flag_blank = 0;
	format->flag_sharp = 0;
}

void get_format(t_format *format, const char *str)
{
	get_per(format, str);
	get_flag(format, str);
	get_width(format, str);
	get_prec(format, str);
	get_type(format, str);
}

int ft_printf(const char *str, ...)
{
	t_format format;

	va_start(format.ap, str);
	format.ret = 0;
	format.index = 0;
	while (str[format.index])
	{
		init_format(&format);
		get_format(&format, str);
		if (str[format.index] == 'c')
			type_c(&format);
		else if (str[format.index] == 's')
			type_s(&format);
		else if (str[format.index] == 'd' || str[format.index] == 'i')
			type_d(&format);
	}
	// printf("format->per : %d\n", format.per);
	// printf("format->flag_minus : %d\n", format.flag_minus);
	// printf("format->flag_plus : %d\n", format.flag_plus);
	// printf("format->flag_blank : %d\n", format.flag_blank);
	// printf("format->flag_zero : %d\n", format.flag_zero);
	// printf("format->width : %d\n", format.width);
	// printf("format->dot : %d\n", format.dot);
	// printf("format->precision : %d\n", format.prec);
	// printf("format->ret : %d\n", format.ret);
	// printf("format->type : %c\n", format.type);
	return (format.ret);
}

// int main(void)
// {
	// ft_printf("%+03.*d\n", -4, 0);
	// printf("---------------\n");
	// printf("%+03.*d\n",-4, 0);
// 	ft_printf("% +.5\n", 100);
// }