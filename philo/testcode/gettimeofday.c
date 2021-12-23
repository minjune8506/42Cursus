#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	struct timeval start;
	struct timeval end;
	double diff;

	gettimeofday(&start, NULL);
	sleep(1);
	gettimeofday(&end, NULL);

	diff = (end.tv_sec * 1000 + end.tv_usec * 1/1000) - (start.tv_sec * 1000 + end.tv_usec * 1/1000);
	printf("%f\n", diff);
	return (0);
}
