#include "ch2.h"

void	ary_reverse(int a[], int n)
{
	int	i;
	for (i = 0 ; i < n / 2 ; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[j]);
		printf("\na[%d]와 a[%d]를 교환합니다.\n", i, n - i - 1);
		swap(int, a[i], a[n - i - 1]);
	}
	for (int j = 0; j < n; j++)
		printf("%d ", a[j]);
	printf("\n역순 정렬을 종료합니다.\n");
}