#include "ch1.h"

int	prac_1(void)
{
	int	a, b, c;
	int	max;

	printf("세 정수의 최댓값을 구합니다. \n");
	printf("a의 값 : "); scanf("%d", &a);
	printf("b의 값 : "); scanf("%d", &b);
	printf("c의 값 : "); scanf("%d", &c);
	max = a;
	if (b > max) max = b;
	if (c > max) max = c;

	printf("최댓값 : %d\n", max);

	return (0);
}