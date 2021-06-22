#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

static void *ft_memcpy(void *dest, void *src, size_t n)
{
	size_t i = 0;

	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

static	char *ft_strdup(char *str)
{
	char *ret;
	int length = ft_strlen(str);
	int i = 0;

	ret = (char *)malloc(length + 1);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char *ret;
	int s1_len;
	int s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(s1_len + s2_len + 1);
	ft_memcpy(ret, s1, s1_len);
	ft_memcpy(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	return (ret);
}

int		get_next_line(char **line)
{
	char *temp;
	char buf[2];
	int read_size = 0;

	if (!line)
		return (-1);
	*line = ft_strdup("");
	while ((read_size = read(0, buf, 1)) > 0)
	{
		buf[read_size] = '\0';
		if (buf[0] == '\n')
			return (1);
		temp = *line;
		*line = ft_strjoin(temp, buf);
		free(temp);
	}
	return (read_size == 0 ? 0 : -1);
}
