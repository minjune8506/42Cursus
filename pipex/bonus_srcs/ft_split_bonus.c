#include "pipex_bonus.h"
#include <stdlib.h>

static int	count_word(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (*s == '\0')
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static int	count_ch(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

static char	**malloc_error(char **ret, int i)
{
	int		j;

	j = 0;
	while (j < i)
		free(ret[j++]);
	free(ret);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(ret = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		if (!count_ch(s, c))
			break ;
		if (!(ret[i] = (char *)malloc(sizeof(char) * (count_ch(s, c) + 1))))
			return (malloc_error(ret, i));
		while (*s && *s != c)
			ret[i][j++] = *s++;
		ret[i++][j] = '\0';
	}
	ret[i] = NULL;
	return (ret);
}
