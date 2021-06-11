#include <stdio.h>

int	main(void)
{
	printf("%l%\n"); //precision무시, width값 적용, flag안들어옴, lenngth무시
	printf("%10.1%\n");
	printf("%10.2%\n");
	printf("%10.3%\n");
	printf("%10.4%\n");

	printf("i : %i\n", 010);
}