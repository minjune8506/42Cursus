/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:36:16 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/02 09:50:48 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdlib.h>

char			*ft_strdup(char *s1)
{
	char	*ret;
	int		index;
	int		len;

	len = ft_strlen(s1);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	index = 0;
	while (s1[index])
	{
		ret[index] = s1[index];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
