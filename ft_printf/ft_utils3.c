/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjune <minjkim2@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:14:55 by minjune           #+#    #+#             */
/*   Updated: 2021/06/11 11:14:57 by minjune          ###   ########.fr       */
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

int num_len_base(long long n, int base)
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
		n /= base;
		length++;
	}
	return (length);
}

char *ft_itoa(long long n)
{
	char *str;
	int length;

	length = num_len_base(n, 10);
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	str[length] = '\0';
	length--;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[length] = '0' + (n % 10);
		n /= 10;
		length--;
	}
	return (str);
}


char *ft_itoa_base(unsigned int num, char *str)
{
	int length;
	char *result;

	length = num_len_base(num, 16);
	result = (char *)malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	result[length] = '\0';
	if (num == 0)
		result[0] = '0';
	while (num != 0)
	{
		result[length - 1] = str[num % 16];
		num /= 16;
		length--;
	}
	return (result);
}
