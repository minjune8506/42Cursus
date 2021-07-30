#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void	print_error()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	split_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int
is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\n' || c == '\f')
		return (1);
	return (0);
}

long long
ft_atoi_long(const char *str)
{
	long long result;
	int sign;

	sign = 1;
	result = 0;
	while (*str && is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}
