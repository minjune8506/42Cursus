/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjune <minjkim2@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:48:08 by minjune           #+#    #+#             */
/*   Updated: 2021/06/09 11:48:10 by minjune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memrcpy(void *dest, const void *src, size_t r_len, size_t s_len)
{
	if (!dest && !src)
		return (NULL);
	while (s_len > 0)
	{
		((unsigned char *)dest)[r_len - 1] = ((unsigned char *)src)[s_len - 1];
		s_len--;
		r_len--;
	}
	return (dest);
}
