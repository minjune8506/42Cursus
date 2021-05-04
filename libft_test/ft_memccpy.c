#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int flag;

	flag = 0;
	while (n > 0 && !flag)
	{
		if (*(unsigned char *)src == c)
			flag = 1;
		*(unsigned char *)dest++ = *(unsigned char *)src++;
		n--;
	}
	if (flag == 1)
		return (dest);
	else
		return (NULL);
}

#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str[50] = "Test String";
	printf("Before ft_memset(): %s\n", str);
//	ft_memccpy(str, "duplicate String",'e', 10);
	memccpy(str, "duplicate String", 'e', 10);
	printf("After ft_memcpy(): %s\n", str);
}
