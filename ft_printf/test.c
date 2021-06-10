#include <stdio.h>

int	main(void)
{
	printf("% 7.5d/% 7.5d\n", 1000, -1000);
	printf("%+7.5d/%+7.5d\n", 1000, -1000);
	printf("%07.5d/%07.5d\n", 1000, -1000);
	printf("%-7.5d/%-7.5d\n", 1000, -1000);
	printf("-----------------------------\n");
	printf("%0 10d\n", 1000);
	printf("%.d\n", 0);
}