#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == c)
			return (str);
		n--;
		str++;
	}
	return (NULL);
}

int main()
{
  char *pch;
  char str[] = "Example String";
  pch = (char*)ft_memchr(str, 'p', 100);

  if (pch != NULL)
    printf("'p' found at position %ld.\n", pch - str + 1);
  else
    printf("'p' not found.\n");
  printf("%s\n", str);

  return 0;
}
