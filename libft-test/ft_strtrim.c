#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_strlcpy.c"
#include "ft_strlen.c"
#include "ft_strdup.c"
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t end;
	size_t index;
	char *ret;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	index = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && strchr(set, s1[end - 1]))
		end--;
	printf("start : %zu, end : %zu\n", start, end);
	if (start >= end)
		return (ft_strdup(""));
	if (!(ret = (char *)malloc(sizeof(char) * (end - start))))
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
	set = "c";
	ret = ft_strtrim(s1, set);
	printf("rt : %s", ret);
}
