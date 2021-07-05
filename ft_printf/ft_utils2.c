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
#include <stdlib.h>

size_t
	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	new_len;

	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

char
	*ft_strdup(const char *s1)
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

char
	*ft_strjoin(char const *s1, char const *s2)
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
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, s1_len);
	ft_memcpy(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	return (ret);
}
