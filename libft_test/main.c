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
				printf("toupper_error\n"); break ;
		}
		index++;
	}
	//tolower
	index = 0;
	while (index <= 128)
	{
		if (ft_tolower(index) != tolower(index))
		{
			printf("tolower_error\n"); break ;
		}
		index++;
	}
	//isalpha
	index = 0;
	while (index <= 128)
	{
		if (ft_isalpha(index) != isalpha(index))
		{
			printf("isalpha_error\n"); break ;
		}
		index++;
	}
	//isdigit
	index = 0;
	while (index <= 128)
	{
		if (ft_isdigit(index) != isdigit(index))
		{
			printf("isdigit_error\n"); break ;
		}
		index++;
	}
	//isalnum
	index = 0;
	while (index <= 128)
	{
		if (ft_isalnum(index) != isalnum(index))
		{
			printf("isalnum_error\n"); break ;
		}
		index++;
	}
	//isascii
	index = 0;
	while (index <= 300)
	{
		if (ft_isascii(index) != isascii(index))
		{
			printf("isascii_error\n"); break ;
		}
		index++;
	}
	//isprint
	index = 0;
	while (index <= 128)
	{
		if (ft_isprint(index) != isprint(index))
		{
			printf("isprint_error\n"); break ;
		}
		index++;
	}
	//strlen
	char *str1;
	
	str1 = "HELLO";
	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str1), strlen(str1));
	str1 = "";
	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str1), strlen(str1));
	str1 = "123ASdqweqzxc";
	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str1), strlen(str1));
	
	//ft_strlcpy
//	char *dst;
//	dst = 0;
//	ft_strlcpy(dst, "HELLO", 6);
//	printf("%s", dst);

	//ft_memset
	printf("-------memset-------\n");
	char *str2;
	int arr[5];
	int i;

	str2 = (char *)malloc(4*sizeof(char));
	ft_memset(str2, 65, 4);
	printf("%s\n", str2);
	ft_memset(arr, 10, 5 * sizeof(int));
	i = 0;
	while (i <= 4)
		printf("%d ", arr[i++]);
	printf("\n-------bzero--------\n");
	//ft_bzero
	ft_bzero(str2, 4);
	ft_bzero(arr, 5);
}
