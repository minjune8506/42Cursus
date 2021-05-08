#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t end;
	char *ret;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	if (!(ret = (char *)malloc(sizeof(char) * (end - start))))
		return (NULL);
	ft_strlcpy(ret, s1 + start, end - start);
	return (ret);
}
