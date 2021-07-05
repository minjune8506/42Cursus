/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typep_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjune <minjkim2@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:05:08 by minjune           #+#    #+#             */
/*   Updated: 2021/06/13 13:05:10 by minjune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	num_len_base_p(unsigned long n, int base)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		length++;
	}
	return (length);
}

char
	*ft_itoa_base_p(unsigned long num, char *str)
{
	char	*result;
	int		length;

	length = num_len_base_p(num, 16);
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

char
	*add_p(char *p_string)
{
	char	*tmp;

	tmp = ft_strjoin("0x", p_string);
	free(p_string);
	p_string = tmp;
	return (p_string);
}
