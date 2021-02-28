#include "ch1.h"

int	q14(void)
{
	int	n;
	int i, j;

	printf("사각형을 출력합니다.\n입력할 수 : ");
	scanf("%d", &n);
	for (i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
			printf("*");
		printf("\n");
	}
	return (0);
}