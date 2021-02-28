#include "ch1.h"

int	sum2(void)
{
	int n;
	int	i = 1;
	int	sum = 0;

	printf("입력 : ");
	scanf("%d", &n);

	while (i != n && i < n)
	{
		i++;
		n--;
		sum += n + i;
	}
	if (i == n)
		sum += n;
	printf("sum : %d\n", sum);
	return (sum);
}