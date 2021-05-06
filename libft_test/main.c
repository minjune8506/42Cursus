#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
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
	//ft_bzero
	printf("\n-------bzero--------\n");	
	ft_bzero(str2, 4);
	printf("%s", str2);
	ft_bzero(arr, 5);
	printf("%s", str2);

	//ft_memcpy
	printf("--------memcpy---------\n");
	char src[] = "BLOCKDMASK";
   	char dest1[] = "";
 	char dest2[] = "abcdefghijklmnop";
//	memcpy(dest1, src, 2); //always overflow(??)
	ft_memcpy(dest2, src, sizeof(char) * 10);
	printf("src : %s\n", src);
	printf("dest1 : %s\n", dest1);
	printf("dest2 : %s\n", dest2);

	//ft_memccpy
	printf("--------memccpy---------\n");
    char str10[50] = "Test String";
    printf("Before ft_memset(): %s\n", str10);
//  ft_memccpy(str10, "duplicate String",'e', 10);
    memccpy(str10, "duplicate String", 'e', 10);
    printf("After ft_memcpy(): %s\n", str10);

	//ft_memmove
	printf("--------memmove---------\n");
	char arraymove[10];
	
	memset(arraymove, 0, sizeof(arraymove));
    strcpy(arraymove, "test");
    printf("original : %s\n", arraymove);
	ft_memmove(arraymove+2, arraymove, strlen("test"));
    //memmove(arraymove+2, arraymove, strlen("test"));
    printf("after memmove : %s\n", arraymove);

	//ft_memchr
	printf("--------memchr---------\n");
	char *pch;
	char strchr[] = "Example String";

	pch = (char*)ft_memchr(strchr, 'p', 100);
	if (pch != NULL)
		printf("'p' found at position %ld.\n", pch - strchr + 1);
	else
		printf("'p' not found.\n");
	printf("%s\n", strchr);

	//ft_memcmp
	printf("--------memcmp---------\n");
	char *strcmp1;
	char *strcmp2;
	int n;

	strcmp1 = "ABC";
	strcmp2 = "";
	n = ft_memcmp(strcmp1, strcmp2, 5);
	printf("%d\n", n);
	
	//ft_strlen
	printf("--------ft_strlen---------\n");
	char *str1;
	
	str1 = "HELLO";
	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str1), strlen(str1));
	str1 = "";
	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str1), strlen(str1));
	str1 = "123ASdqweqzxc";
	printf("ft_strlen : %zu, strlen : %zu\n", ft_strlen(str1), strlen(str1));

	//ft_strlcpy
	printf("--------ft_strlcpy---------\n");
	char dstcpy[10];
	ft_strlcpy(dstcpy, "HELLO", 6);
	printf("%s\n", dstcpy);
	
	//ft_strlcat
	printf("--------ft_strlcat---------\n");
	char dstcat[10] = "HI";
	int	retcat;

	retcat = ft_strlcat(dstcat, "HELLO", 3);
	printf("dst : %s , return : %d\n", dstcat, retcat);
	retcat = ft_strlcat(dstcat, "HELLO", 0);
	printf("dst : %s , return : %d\n", dstcat, retcat);
	retcat = ft_strlcat(dstcat, "HELLO", 2);
	printf("dst : %s , return : %d\n", dstcat, retcat);
	
	//ft_strchr
	printf("--------ft_strchr---------\n");
	char *strchr2;

	strchr2 = "ABCDEFGHIJK";
	strchr2 = ft_strchr(strchr2, '\0');
	printf("%c\n", *strchr2);

	//ft_strrchr
	printf("--------ft_strrchr---------\n");
	char *strchr3;

	strchr3 = "AABBCCCDDEEE";
	strchr3 = ft_strrchr(strchr3, '\0');
	printf("%s\n", strchr3);
	
	//ft_strnstr
	printf("--------ft_strrchr---------\n");
	char *haystack;
	char *needle;

	haystack = "THIS HAYSTACK IS HAYSTACK";
	needle = "IS";
	haystack = strnstr(haystack, needle, 3);
	printf("%s\n", haystack);

	//ft_strncmp
	printf("--------ft_strncmp---------\n");
	char *cmp1;
	char *cmp2;
	int	ret_cmp;

	cmp1 = "HI EVERYONE";
	cmp2 = "HI FVERY";
	ret_cmp = ft_strncmp(cmp1, cmp2, 4);
	printf("%d\n", ret_cmp);

	//ft_atoi
	printf("--------ft_atoi---------\n");
	printf("atoi : %d ft_atoi : %d\n",atoi("--1234"), ft_atoi("--1234"));
	printf("atoi : %d ft_atoi : %d\n",atoi("-+1234"), ft_atoi("-+1234"));
	printf("atoi : %d ft_atoi : %d\n",atoi("10000000000"), ft_atoi("10000000000"));
	printf("atoi : %d ft_atoi : %d\n",atoi("2147483648"), ft_atoi("2147483648"));

	//toupper
	int	index;
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
	//calloc
	printf("--------ft_calloc---------\n");
	int	*cal;

	cal = (int *)calloc(2, sizeof(int));
	printf("%d\n", cal[1]);
	printf("%d\n", cal[2]);
	printf("%d\n", cal[3]);
	printf("%d\n", cal[4]);
	printf("%d\n", cal[5]);
	printf("%d\n", cal[6]);
	//strdup
	printf("--------ft_strdup---------\n");
	char *dup;
	char *dup_ret;

	dup = "Duplicate this";
	dup_ret = ft_strdup(dup);
	printf("%s\n", dup_ret);

}
