#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		find(char *str, char c, int index)
{
	int i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i])
	{
		if (find(s1, s1[i], i))
				ft_putchar(s1[i]);
		i++;
	}

	while (s2[j])
	{
		if (find(s1, s2[j], i) && find(s2, s2[j], j))
			ft_putchar(s2[j]);
		j++;
	}
}
int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	else
		ft_putchar('\n');
}
