#include <stdbool.h>
#include <stdio.h>

typedef int test;

int	main(void)
{
	bool t1;
	test t2;

	t1 = true;
	printf("%d\n", t1);
	printf("size : %lu\n", sizeof(t1));
}
