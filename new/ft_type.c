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
#include <stdlib.h>
#include <stdarg.h>

void	type_c(t_format *format)
{
	char *ret;
	int length;

	ret = ft_malloc(format, 1);
	length = ft_strlen(ret);
	if (format->flag == 0)
		ret[length - 1] = va_arg(format->ap, int);
	else
		ret[0] = va_arg(format->ap, int);
	ft_putstr(ret, length);
	free(ret);
	format->ret += length;
	format->index++;
}

void	type_s(t_format *format)
{
	char *s_string;
	char *ret;
	int str_len;

	s_string = va_arg(format->ap, char *);
	if (!(s_string))
		s_string = "(null)";
	str_len = ft_strlen(s_string);
	if (format->prec > -1 && format->prec < str_len)
	{
		s_string = ft_substr(s_string, 0, format->prec);
		str_len = ft_strlen(s_string);
	}
	ret = ft_malloc(format, str_len);
	if (format->flag == 0)
		ft_memrcpy(ret, s_string, ft_strlen(ret), str_len);
	else
		ft_memcpy(ret, s_string, ft_strlen(s_string));
	if (format->prec > -1 && format->prec < str_len)
		free(s_string);
	ft_putstr(ret, ft_strlen(ret));
	free(ret);
	format->index++;
	format->ret += ft_strlen(ret);
}

void	type_d(t_format *format)
{
	
}