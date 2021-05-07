#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret;
	size_t s1_len;
	size_t s2_len;

	s1_len = strlen(s1);
	s2_len = strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len));
	if (!ret)
		return (NULL);
	memcpy(ret, s1, s1_len);
	memcpy(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	return (ret);
}

int	main(void)
{
	char *s1;
	char *s2;
	char *ret;

	s1 = "abc";
	s2 = "def";
	ret = ft_strjoin(s1, s2);
	printf("%s\n", ret);
	free(ret);
	return (0);
}
