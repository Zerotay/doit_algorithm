#include "ch1.h"

int	q15(void)
{
	int	n1;
	int	n2;
	int i, j;

	printf("직사각형을 출력합니다.\n");
	printf("높이 : ");
	scanf("%d", &n1);
	printf("너비 : ");
	scanf("%d", &n2);
	for (i = 0 ; i < n1 ; i++)
	{
		for(j = 0 ; j < n2 ; j++)
			printf("*");
		printf("\n");
	}
	return (0);
}