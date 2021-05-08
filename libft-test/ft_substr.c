#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ret;
	int index;
	
	if (!s)
		return (NULL);
	index = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
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
