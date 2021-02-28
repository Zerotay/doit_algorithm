#include "ch1.h"

int	sum1(void)
{
	int n;
	int i = 0;
	int sum = 0;

	printf("입력 : ");
	scanf("%d", &n);
	while (++i <= n)
	{
		sum += i;
		printf("%d ", i);
		if (i != n)
			printf("+ ");
		else
		{
			printf("= %d\n", sum);
			return (0);
		}
	}
	return (1);
}