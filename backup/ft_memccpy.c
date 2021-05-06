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
