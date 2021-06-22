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

void	ft_inter(char *s1, char *s2)
{
	int i = 0;
	int j;
	
	while (s1[i])
	{
		j = 0;
		if (find(s1, s1[i], i))
		{
			while (s2[j])
			{
				if (s1[i] == s2[j])
				{
					ft_putchar(s1[i]);
					break;
				}
				j++;
			}
		}
		i++;
	}
}
int	main(int ac, char **av)
{
	if (ac == 3)
		ft_inter(av[1], av[2]);
	else
		ft_putchar('\n');
}
