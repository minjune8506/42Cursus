#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_strlcpy.c"
#include "ft_strlen.c"
//ft_strlen 햇을때 이상한 값이 나온다 end 에서
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t end;
	size_t index;
	char *ret;

	if (!s1)
		return (NULL);
	if (!set)
		return (strdup(s1));
	index = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && strchr(set, s1[start]))
		start++;
	printf("start : %zu\n", start);
	while (s1[end - 1] && strchr(set, s1[end - 1]))
		end--;
	printf("end : %zu\n", end);
	ret = (char *)malloc(sizeof(char) * (end - start));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1 + start, end - start);
	return (ret);
}

int	main(void)
{
	char *s1;
	char *set;
	char *ret;

	s1 = "";
	set = "AB";
	ret = ft_strtrim(s1, set);
	printf("rt : %s", ret);
}
