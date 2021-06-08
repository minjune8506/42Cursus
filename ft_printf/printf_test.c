#include <stdio.h>
#include <stdarg.h>

int	main(void)
{
	// - 와 0 의 관계
	// printf("%c\n", 'a'); //a
	// printf("%10c\n", 'a'); //폭 10칸 지정 가능
	// //printf(".1c\n", 'a'); //%c에서 정밀도 지정 불가능
	// printf("%lc\n", 'a'); //서식지정자 길이
	// printf("%-10c\n", 'a'); //폭 10 칸 지정, - 왼쪽 정렬 가능
	// //printf("%+10c\n", 'a'); // + -> 양수일때는 + 음수일떄는 - 출력 //불가능
	// //printf("%010c\n", 'a'); // %c에서 '0'플래그 지정 불가능
	// //printf("% c\n", 'a');  // ' ' -> 불가능
	// // printf("%#c\n", 'a'); // '#' -> 불가능
	printf("%-c\n", 'a');
	printf("%-4c\n", 'a');
	printf("abc%-5c\n", 'a');
	printf("%3c\n", 'a');
	printf("%4c\n", 'a');
	//printf("%0c\n", 'a');
	printf("%s\n", "abc");
	printf("%-s\n", "bcd");
	printf("%-4s\n", "bcd");
	printf("%5s\n", "bcd");
	//서식 지정자 s의 경우 '0'flag 불가능
	int i = 0;
	i = printf("%c, %c", 'a', 'b');
	printf("%d", i);
}