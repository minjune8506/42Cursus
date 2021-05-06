#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int index;
	char *str1;
	char *str2;
	char str3[20] = "TEST STRING";
	int arr[5];

	//ft_memset
	printf("-------memset-------\n");
	str2 = (char *)malloc(4*sizeof(char));
	ft_memset(str2, 65, 4);
	printf("%s\n", str2);
	ft_memset(arr, 10, 5 * sizeof(int));
	index = 0;
	while (index <= 4)
		printf("%d ", arr[index++]);
	free(str2);

	//ft_bzero
	printf("\n-------bzero--------\n");	
	ft_bzero(str2, 4);
	printf("%s", str2);
	ft_bzero(arr, 5);
	printf("%d", arr[1]);

	//ft_memcpy
	printf("--------memcpy---------\n");
	char src[] = "BLOCKDMASK";
   	char dest1[] = "";
 	char dest2[] = "abcdefghijklmnop";
	memcpy(dest1, src, 2);
	ft_memcpy(dest2, src, sizeof(char) * 10);
	printf("src : %s\n", src);
	printf("dest1 : %s\n", dest1);
	printf("dest2 : %s\n", dest2);
	
	//ft_memccpy
	printf("--------memccpy-------\n");
	printf("Before ft_memccpy() : %s\n", str3);
	ft_memccpy(str3, "duplicate String", 'e', 10);
	printf("After ft_memccpy() : %s\n", str3);

	//ft_memmove
	printf("-------ft_memmove------\n");
	char arr2[10];

	ft_memset(arr2, 0, sizeof(arr2));
	strcpy(arr2, "test");
	printf("original : %s\n", arr2);
	ft_memmove(arr2 + 2, arr2, strlen("test"));
	printf("after memmove : %s\n", arr2);

	//ft_memchr
	printf("------ft_memchr--------\n");
	char *pch;
	char str4[] = "EXAMPLE STRING";
	pch = (char *)ft_memchr(str4, 'p', 30);

	if (pch != NULL)
		printf("'p' found at position %ld.\n", pch - str4 + 1);
	else
		printf("'p' not found.\n");
	printf("%s\n", str4);

	//ft_memcmp
	printf("-------ft_memcmp-----\n");
	str1 = "ABC";
	str2 = "";
	index = ft_memcmp(str1, str2, 5);
	printf("%d\n", index);

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
//	char *str1;
//	
//	str1 = "HELLO";
//	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str1), strlen(str1));
//	str1 = "";
//	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str1), strlen(str1));
//	str1 = "123ASdqweqzxc";
//	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str1), strlen(str1));
	
	//ft_strlcpy
//	char *dst;
//	dst = 0;
//	ft_strlcpy(dst, "HELLO", 6);
//	printf("%s", dst);

}
