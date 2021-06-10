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
	if (format->flag_minus == 0)
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

#include <stdio.h>

static int num_length(int n)
{
	int length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char *ft_itoa(int n)
{
	char *str;
	long long nbr;
	int length;

	nbr = n;
	length = num_length(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	str[length] = '\0';
	length--;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[length] = '0' + (nbr % 10);
		nbr /= 10;
		length--;
	}
	return (str);
}

char	*create_pre_str(t_format *format, char *d_string, int num_len)
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
	return (ret);
}

char		*ft_strdup(const char *s1)
{
	char	*ret;
	int		index;

	index = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ret)
		return (NULL);
	while (s1[index])
	{
		ret[index] = s1[index];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_memcpy(ret, s1, s1_len);
	ft_memcpy(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	return (ret);
}

void type_d(t_format *format)
{
	char *d_string;
	char *flag_str;
	char *ret;
	int num_len;
	int num;

	num = va_arg(format->ap, int);
	d_string = ft_itoa(num);
	num_len = num_length(num);
	//prec 처리
	if (format->prec > -1 && format->prec >= num_len)
		d_string = create_pre_str(format, d_string, num_len);
	else if (format->prec == 0 && num == 0)
		d_string = ft_strdup("");
	// printf("d_string : %s\n", d_string);
	//flag 처리(' ' && '+')
	if (format->flag_blank == 1 && num >= 0)
	{
		flag_str = ft_strjoin(" ", d_string);
		if (format->prec > -1 && format->prec > num_len)
			free(d_string);
		d_string = flag_str;
	}
	else if (format->flag_plus == 1 && num >= 0)
	{
		flag_str = ft_strjoin("+", d_string);
		if (format->prec > -1 && format->prec > num_len)
			free(d_string);
		d_string = flag_str;
	}
	// printf("d_string : %s\n", d_string);
	ret = ft_malloc(format, ft_strlen(d_string));
	if (format->flag_minus == 0)
	{
		if (format->flag_zero == 1 && format->prec == -1)
		{
			ft_memset(ret, '0', ft_strlen(ret));
			ft_memrcpy(ret, d_string, ft_strlen(ret), ft_strlen(d_string));
			int i = 0;
			while (ret[i])
			{
				if (ret[i] == '-')
				{
					ret[i] = '0';
					ret[0] = '-';
				}
				else if (ret[i] == '+')
				{
					ret[i] = '0';
					ret[0] = '+';
				}
				else if (ret[i] == ' ')
				{
					ret[i] = '0';
					ret[0] = ' ';
				}
				i++;
			}
		}
		else
			ft_memrcpy(ret, d_string, ft_strlen(ret), ft_strlen(d_string));
	}
	else
		ft_memcpy(ret, d_string, ft_strlen(d_string));
	ft_putstr(ret, ft_strlen(ret));
	format->index++;
	format->ret += ft_strlen(ret);
}