/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:24:25 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/20 15:24:31 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

void
	free_int(int **value, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(value[j++]);
	free(value);
}

void
	free_uint(unsigned int **value, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(value[j++]);
	free(value);
}

unsigned int
	**color_allocate(t_data **data)
{
	unsigned int	**ptr;
	int				i;

	i = 0;
	ptr = (unsigned int **)malloc(sizeof(unsigned int *) * (*data)->height);
	if (!ptr)
		print_error("malloc");
	while (i < (*data)->height)
	{
		ptr[i] = (unsigned int *)malloc(sizeof(unsigned int) * (*data)->width);
		ft_bzero(ptr[i], (*data)->width);
		if (!ptr[i])
		{
			free_uint(ptr, i);
			print_error("malloc");
		}
		i++;
	}
	return (ptr);
}

int	
	**z_allocate(t_data **data)
{
	int	**ptr;
	int	i;

	i = 0;
	ptr = (int **)malloc(sizeof(int *) * (*data)->height);
	if (!ptr)
		print_error("malloc");
	while (i < (*data)->height)
	{
		ptr[i] = (int *)malloc(sizeof(int) * (*data)->width);
		ft_bzero(ptr[i], (*data)->width);
		if (!ptr[i])
		{
			free_int(ptr, i);
			print_error("malloc");
		}
		i++;
	}
	return (ptr);
}
