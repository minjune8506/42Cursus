/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjune <minjkim2@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:10:23 by minjune           #+#    #+#             */
/*   Updated: 2021/06/13 13:10:23 by minjune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_p(t_format *format)
{
	char			*p_string;
	char			*ret;
	unsigned long	num;

	num = va_arg(format->ap, unsigned long);
	p_string = ft_itoa_base_p(num, "0123456789abcdef");
	if (format->prec >= -1 && format->prec >= ft_strlen(p_string))
		p_string = create_pre_str(format, p_string, ft_strlen(p_string));
	else if (format->prec == 0 && num == 0)
	{
		free(p_string);
		p_string = ft_strdup("");
	}
	p_string = add_p(p_string);
	ret = ft_malloc(format, ft_strlen(p_string));
	ret = minus_flag(ret, p_string, format);
	ft_putstr(ret, ft_strlen(ret));
	format->index++;
	format->ret += ft_strlen(ret);
	free_all(ret, p_string);
}

void	type_per(t_format *format)
{
	char	*ret;
	int		length;

	ret = ft_malloc(format, 1);
	length = ft_strlen(ret);
	if (format->flag_minus == 0)
	{
		if (format->flag_zero == 1)
			ft_memset(ret, '0', ft_strlen(ret));
		ret[length - 1] = '%';
	}
	else
		ret[0] = '%';
	ft_putstr(ret, length);
	free(ret);
	format->ret += length;
	format->index++;
}
