/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:36:51 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/08 20:19:45 by minjune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;
	size_t	haystack_len;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (haystack_len < needle_len || len < needle_len)
		return (NULL);
	if (haystack_len > len)
		size = len;
	else
		size = haystack_len;
	while (size >= needle_len)
	{
		if (ft_memcmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		size--;
	}
	return (NULL);
}
