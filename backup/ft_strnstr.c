/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:36:51 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/06 16:01:11 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int index;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		if (*haystack == needle[0])
		{
			index = 0;
			while (needle[index])
			{
				if (*haystack != needle[index])
					break ;
				if (needle[index] == '\0')
					return ((char *)haystack);
				haystack++;
				index++;
				len--;
			}
		}
		haystack++;
		len--;
	}
	return (NULL);
}
