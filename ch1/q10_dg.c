#include "ch1.h"

int	minus1(void)
{
	int a, b;
	printf("a의 값 : ");
	scanf("%d", &a);
	do
	{
		printf("b의 값 : ");
		scanf("%d", &b);
		if (a >= b)
			printf("a보다 큰 값을 입력하세요!\n");
	} while (a >= b);
	printf("b - a는 %d입니다.\n", b - a);
	return (b - a);
}