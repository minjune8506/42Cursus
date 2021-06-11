/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjune <minjkim2@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:49:54 by minjune           #+#    #+#             */
/*   Updated: 2021/06/11 22:49:55 by minjune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
