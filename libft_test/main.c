#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int index;
	
	//toupper
	index = 0;
	while (index <= 128)
	{
		if (ft_toupper(index) != toupper(index))
		{
				printf("error\n"); break ;
		}
		index++;
	}
	//tolower
	index = 0;
	while (index <= 128)
	{
		if (ft_tolower(index) != tolower(index))
		{
			printf("error\n"); break ;
		}
		index++;
	}
	//isalpha
	index = 0;
	while (index <= 128)
	{
		if (ft_isalpha(index) != isalpha(index))
		{
			printf("error\n"); break ;
		}
		index++;
	}
	//isdigit
	index = 0;
	while (index <= 128)
	{
		if (ft_isdigit(index) != isdigit(index))
		{
			printf("error\n"); break ;
		}
		index++;
	}
	//isalnum
	index = 0;
	while (index <= 128)
	{
		if (ft_isalnum(index) != isalnum(index))
		{
			printf("error\n"); break ;
		}
		index++;
	}
	//isascii
	index = 0;
	while (index <= 300)
	{
		if (ft_isascii(index) != isascii(index))
		{
			printf("error\n"); break ;
		}
		index++;
	}
	//isprint
	index = 0;
	while (index <= 128)
	{
		if (ft_isprint(index) != isprint(index))
		{
			printf("error\n"); break ;
		}
		index++;
	}
	//strlen
	char *str;
	str = "Hello";
	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str), strlen(str));
	str = "";
	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str), strlen(str));
	str = "123ASdqweqzxc";
	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str), strlen(str));
	//ft_strlcpy
	char *dst;

	dst = 0;
	ft_strlcpy(dst, "HELLO", 6);
	printf("%s", dst);
}
