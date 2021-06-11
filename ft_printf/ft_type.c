/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:51:08 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/08 20:51:08 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

void type_c(t_format *format)
{
	char *ret;
	int length;

	ret = ft_malloc(format, 1);
	length = ft_strlen(ret);
	if (format->flag_minus == 0)
		ret[length - 1] = va_arg(format->ap, int);
	else
		ret[0] = va_arg(format->ap, int);
	ft_putstr(ret, length);
	free(ret);
	format->ret += length;
	format->index++;
}

void type_s(t_format *format)
{
	char *s_string;
	char *ret;

	s_string = va_arg(format->ap, char *);
	if (!(s_string))
		s_string = "(null)";
	if (format->prec > -1 && format->prec < ft_strlen(s_string))
		s_string = ft_substr(s_string, 0, format->prec);
	ret = ft_malloc(format, ft_strlen(s_string));
	ret = minus_flag(ret, s_string, format);
	if (format->prec > -1 && format->prec < ft_strlen(s_string))
		free(s_string);
	ft_putstr(ret, ft_strlen(ret));
	free(ret);
	format->index++;
	format->ret += ft_strlen(ret);
}

void type_d(t_format *format)
{
	char *d_string;
	char *ret;
	int num;

	num = va_arg(format->ap, int);
	d_string = ft_itoa(num);
	if (format->prec > -1 && format->prec >= num_length(num))
		d_string = create_pre_str(format, d_string, num_length(num));
	else if (format->prec == 0 && num == 0)
	{
		free(d_string);
		d_string = ft_strdup("");
	}
	d_string = control_flag(d_string, num, format);
	ret = ft_malloc(format, ft_strlen(d_string));
	ret = minus_flag(ret, d_string, format);
	ft_putstr(ret, ft_strlen(ret));
	format->index++;
	format->ret += ft_strlen(ret);
	free_all(ret, d_string);
}