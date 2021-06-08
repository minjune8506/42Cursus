#include <stdio.h>
#include <stdarg.h>

int main(void)
{
	// - 와 0 의 관계
	// printf("%c\n", 'a'); //a
	// printf("%10c\n", 'a'); //폭 10칸 지정 가능
	// printf(".1c\n", 'a'); //%c에서 정밀도 지정 불가능
	// printf("%lc\n", 'a'); //서식지정자 길이
	// printf("%-10c\n", 'a'); //폭 10 칸 지정, - 왼쪽 정렬 가능
	// printf("%+10c\n", 'a'); // + -> 양수일때는 + 음수일떄는 - 출력 //불가능
	// printf("%010c\n", 'a'); // %c에서 '0'플래그 지정 불가능
	// printf("% c\n", 'a');  // ' ' -> 불가능
	// printf("%#c\n", 'a'); // '#' -> 불가능
	// printf("printf : %-2c %3c %-2c\n", 'a', 'b', 'c');
	//printf("ft_printf : %-4.c\n", 'a');
	// printf("%4c\n", 'a');
	// printf("%-1c\n", 'a');
	// printf("ft_printf : %c\n", 'a');
	// printf("abc%-5c\n", 'a');
	// 	ft_printf("%3c %c", 'a', 'b');
	// 	ft_printf("%4c\n", 'a');
	// 	ft_printf("%c %2c %-2c %5c", 'a', 'b', 'c', 'd');
	//	printf("%0c\n", 'a');
	// 	int i = 0;
	// 	i = printf("%c", 'a');
	// 	printf("%d", i);
	
	//--------------------------------%s-------------------------------------------
	//서식 지정자 s의 경우 '0'flag 불가능
	printf("%s\n", "HELLO");
	printf("%-5s\n", "HI");
	printf("%5s\n", "HIE");
	printf("%s\n%s\n", "HEL", "LO");
	printf("%--4.s\n", "HELLO");
}