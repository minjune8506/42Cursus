/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeu_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjune <minjkim2@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:24:29 by minjune           #+#    #+#             */
/*   Updated: 2021/06/11 15:24:30 by minjune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int num_len_base(unsigned int n, int base)
{
	int length;

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

char *ft_itoa_u(unsigned int n)
{
	char *str;
	unsigned long long nbr;
	int length;

	nbr = n;
	length = num_len_base(nbr, 10);
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