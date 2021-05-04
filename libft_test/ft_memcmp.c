#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}


int main() {
  char *str1;
  char *str2;
  int n;
  
  str1 = "ABC";
  str2 = "";
  n = ft_memcmp(str1, str2, 5);

  printf("%d\n", n);
  return 0;
}
