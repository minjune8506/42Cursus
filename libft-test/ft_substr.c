#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ret;
	int index;

	index = 0;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (len > 0)
	{
		ret[index] = s[start];
		index++;
		start++;
		len--;
	}
	ret[index] = '\0';
	return (ret);
}

int	main(void)
{
	char *s;
	int start;
	size_t len;

	s = "  abcdef  ";
	start = 2;
	len = 3;
	s = ft_substr(s, start, len);
	printf("%s\n", s);
	free(s);
}
