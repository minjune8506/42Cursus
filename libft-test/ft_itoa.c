#include <stdlib.h>
#include <stdio.h>

int	num_length(long long n)
{
	int length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	nbr;
	int		length;

	nbr = n;
	length = num_length(nbr);
	printf("input number : %d\n", n);
	printf("length : %d\n", length);
	if (!(str = (char *)malloc(sizeof(char) *(length + 1))))
		return (NULL);
	str[length] = '\0';
	length--;
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[length] = '0' + (nbr % 10);
		nbr /= 10;
		length--;
	}
	return (str);
}

int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}
