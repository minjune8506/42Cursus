#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ft_strlcpy.c"
#include "ft_strlen.c"
#include "ft_strdup.c"
#include "ft_strchr.c"
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t end;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	printf("start : %zu\n", start);
	printf("end : %zu\n", end);
	while (start <= end && ft_strchr(set, s1[start]))
		start++;
	printf("start : %zu\n", start);
	while (0 <= end && ft_strchr(set, s1[end - 1]))
		end--;
	printf("end : %zu\n", end);
	if (start >= end)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);	


int	main(void)
{
	char *s1, *set, *ret;

	s1 = "";
	set = "ABC";
	ret = ft_strtrim(s1, set);
	printf("%s\n", ret);
}
