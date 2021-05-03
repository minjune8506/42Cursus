#include "libft.h"
#include <ctype.h>
#include <stdio.h>

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
}

//printf("ft_toupper : %d , to_upper : %d\n", ft_toupper(index), toupper(index));
