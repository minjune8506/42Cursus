#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

char	f(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	if (i > 100)
		printf(" ");
	return (c);
}

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
	char src[] = "srcstring";
   	char dest1[] = "abc";
 	char dest2[] = "abc";
	char *ret_memcpy;
//	memcpy(dest1, src, 2); //always overflow(??)
	ret_memcpy = memcpy(NULL, NULL,3);
	//memcpy(dest2, src, 3);
	printf("ret : %s\n", ret_memcpy);
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
	int tab[7] = {-49, 49, 1, 0, -1, -2, 2};
	pch = (char*)ft_memchr(tab, -1 , 7);
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
	printf("--------ft_strnstr---------\n");
	char *haystack;
	char *needle;
	char *strnstr_ret;

	haystack = "THIS HAYSTACK";
	needle = "IS";
	strnstr_ret = ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15);
	printf("%s\n", strnstr_ret);
	strnstr_ret = ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 15);
	printf("%s\n", strnstr_ret);
	strnstr_ret = ft_strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum", 35);
	printf("%s\n", strnstr_ret);
	strnstr_ret = ft_strnstr("lorem ipsum dolor sit amet", "", 10);
	printf("%s\n", strnstr_ret);
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

	//ft_substr
	printf("--------ft_substr---------\n");
	char *sub_str;

	sub_str = "abcdef";	
	sub_str = ft_substr(sub_str, 5, 3);
	printf("%s\n", sub_str);
	sub_str = ft_substr(sub_str, 6, 3);
	printf("%s\n", sub_str);
	free (sub_str);

	//ft_strjoin
	printf("--------ft_strjoin---------\n");
	char	*join1;
	char	*join2;
	char	*join_ret;

	join1 = "ABC";
	join2 = "DEF";
	join_ret = ft_strjoin(join1, join2);
	printf("%s\n", join_ret);
	free(join_ret);
	
	//ft_strtrim
	printf("--------ft_strtrim---------\n");
	char *trim1;
	char *trimset;
	char *trim_ret;

	trim1 = "";
	trimset = "c";
	trim_ret = ft_strtrim(trim1, trimset);
	printf("ret : %s\n", trim_ret);

	//ft_split
	printf("--------ft_split---------\n");
	char *split = "          ";
	char c = ' ';
	char **ret_split = ft_split(split, c);
	int index_split = 0;
	while (ret_split[index_split])
		printf("ret :%s\n", ret_split[index_split++]);
	
	//ft_itoa
	printf("--------ft_itoa---------\n");
	printf("%s\n", ft_itoa(-2147483648));

	//ft_strmapi
	printf("--------ft_strmapi---------\n");
	char *s = "abcde";
	printf("%s\n", ft_strmapi(s, f));
	
	//ft_putchar_fd
	int fd;
	fd = open("test", O_RDWR, S_IRWXU);
	ft_putchar_fd('A', fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("test str\n", fd);
	ft_putendl_fd("putendl_fd_test", fd);
	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(2147483647, fd);
	ft_putchar_fd('\n', fd);

	//ft_atoi
	printf("atoi : %d\n", atoi("9223372036854775807"));
	printf("atoi : %d\n", atoi("-214748123123213123213648"));
}
