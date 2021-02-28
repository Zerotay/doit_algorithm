#include "ch1.h"

void spira(int n)
{
	int i, j;

	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n + i ; j++) // 2n-1에서 왼쪽 공백 날린 갯수
			if (j < n - i - 1)
				printf(" ");
			else
				printf("*");
		printf ("\n");
	}
}