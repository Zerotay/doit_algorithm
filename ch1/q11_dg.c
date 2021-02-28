#include "ch1.h"

int	width(void)
{
	int n;
	int	i = 1;

	do
	{
		printf("n의 값 : ");
		scanf("%d", &n);
	} while (n <= 0);
	while (n /= 10)
	{
		i++;
	}
	printf("그 수는 %d자리입니다.\n", i);
	return (0);
}