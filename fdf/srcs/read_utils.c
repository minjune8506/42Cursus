#include "fdf.h"
#include "libft/libft.h"
#include <stdlib.h>

void
	fill_zvalue(char *line, int **value, t_data **data)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(line, ' ');
	while (i < (*data)->width)
	{
		(*value)[i] = ft_atoi(temp[i]);
		free(temp[i]);
		i++;
	}
	free(temp);
}

void
	fill_color(char *line, unsigned int **color)
{
	char	**temp;
	int		i;
	int		j;

	temp = ft_split(line, ' ');
	i = 0;
	while (temp[i])
	{
		if (ft_find(temp[i], ',') > 0)
		{
			j = ft_find(temp[i], ',');
			(*color)[i] = ft_atoi_base(temp[i] + j + 3);
		}
		else
			(*color)[i] = 0;
		free(temp[i++]);
	}
	free(temp);
}
