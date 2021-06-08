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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *ptr;

	ptr = s;
	while (n)
	{
		*ptr++ = (unsigned char)c;
		n--;
	}
	return (s);
}

char	*ft_malloc(t_format *format, int str_len)
{
	char *ret;

	if (format->width >= str_len)
	{
		ret = (char *)malloc(format->width + 1);
		ft_memset(ret, ' ', format->width + 1);
		ret[format->width] = '\0';
	}
	else
	{
		ret = (char *)malloc(str_len + 1);
		ft_memset(ret, ' ', str_len + 1);
		ret[str_len] = '\0';
	}
	return (ret);
}

void	type_c(t_format *format)
{
	char *c_string;
	int length;

	c_string = ft_malloc(format, 1);
	length = ft_strlen(c_string);
	if (format->flag == 0)
		c_string[length - 1] = va_arg(format->ap, int);
	else
		c_string[0] = va_arg(format->ap, int);
	ft_putstr(c_string, length);
	free(c_string);
	format->ret += length;
	format->index++;
}