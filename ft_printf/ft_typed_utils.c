/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjune <minjkim2@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:59:43 by minjune           #+#    #+#             */
/*   Updated: 2021/06/11 13:59:44 by minjune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char *check_sign(char *ret)
{
	int i;
	char temp;

	i = 0;
	while (ret[i])
	{
		if (ft_strchr("-+ ", ret[i]))
		{
			temp = ret[i];
			ret[i] = '0';
			ret[0] = temp;
		}
		else if (ft_strchr("xX", ret[i]))
		{
			temp = ret[i];
			ret[i] = '0';
			ret[1] = temp;
		}
		i++;
	}
	return (ret);
}

char *create_pre_str(t_format *format, char *d_string, int num_len)
{
	char *ret;

	if (*d_string == '-')
	{
		ret = (char *)malloc(format->prec + 2);
		ret[format->prec + 1] = '\0';
		ft_memset(ret, '0', format->prec + 1);
		ret[0] = '-';
		ft_memcpy(&ret[format->prec - num_len + 2], d_string + 1, num_len);
	}
	else
	{
		ret = (char *)malloc(format->prec + 1);
		ret[format->prec] = '\0';
		ft_memset(ret, '0', format->prec);
		ft_memcpy(&ret[format->prec - num_len], d_string, num_len);
	}
	free(d_string);
	return (ret);
}

char *control_flag(char *d_string, int num, t_format *format)
{
    char *flag_str;

	if (format->flag_blank == 1 && num >= 0)
	{
		flag_str = ft_strjoin(" ", d_string);
		free(d_string);
	}
	else if (format->flag_plus == 1 && num >= 0)
	{
		flag_str = ft_strjoin("+", d_string);
		free(d_string);
	}
	else if (format->flag_sharp && num != 0)
	{
		if (format->type == 'x')
			flag_str = ft_strjoin("0x", d_string);
		if (format->type == 'X')
			flag_str = ft_strjoin("0X", d_string);
		free(d_string);
	}
    else
		flag_str = d_string;
    return (flag_str);
}

char *minus_flag(char *ret, char *d_string, t_format *format)
{
	if (format->flag_minus == 0)
	{
		if (format->flag_zero == 1 && format->prec == -1)
		{
			ft_memset(ret, '0', ft_strlen(ret));
			ft_memrcpy(ret, d_string, ft_strlen(ret), ft_strlen(d_string));
			//마지막에 d i x X 제외한 케이스로 변경
			if (format->type == 'd' || format->type == 'i' || format->type == 'x' || format->type == 'X')
				ret = check_sign(ret);
		}
		else
			ft_memrcpy(ret, d_string, ft_strlen(ret), ft_strlen(d_string));
	}
	else
		ft_memcpy(ret, d_string, ft_strlen(d_string));
	return (ret);
}

void	free_all(char *ret, char *d_string)
{
	free(d_string);
	free(ret);
}
