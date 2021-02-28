#include "ch1.h"

void	nrpira(int n)
{
	int i, j;

	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < 2 * n - 1 - i ; j++)
			if (j <= i - 1)
				printf(" ");
			else
				printf("%d", (i + 1) % 10);
		printf ("\n");
	}
}