/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjune <minjkim2@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:29:39 by minjune           #+#    #+#             */
/*   Updated: 2021/06/09 14:29:40 by minjune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	length;

	if (!dst)
		return (0);
	index = 0;
	length = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[index] && index < (dstsize - 1))
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (length);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	new_len;

	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}