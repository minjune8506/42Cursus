#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *tmp;
	const char *s;

	if (dest <= src)
	{
		tmp = dest;
		s = src;
		while (n--)
			*tmp++ = *s++;
	}
	else
	{
		tmp = dest;
		tmp += n;
		s = src;
		s += n;
		while (n--)
			*--tmp = *--s;
	}
	return (dest);
}

#include <string.h>
#include <stdio.h>

int main(void)
{
        char array[10];

        memset(array, 0, sizeof(array));
        strcpy(array, "test");

        printf("original : %s\n", array);

//	ft_memmove(array+2, array, strlen("test"));
	memmove(array+2, array, strlen("test"));
        printf("after memmove : %s\n", array);

        return 0;
}
