#include "ch1.h"

void triangleLB(int n)
{
	int i, j;

	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j <= i ; j++)
			printf("*");
		printf("\n");
	}
}

void triangleLU(int n)
{
	int i, j;

	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n - i ; j++)
			printf("*");
		printf("\n");
	}
}

void triangleRU(int n)
{
	int i, j;

	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n ; j++)
			if (j < i)
				printf(" ");
			else
				printf("*");
		printf("\n");
	}
}

void triangleRB(int n)
{
	int i, j;

	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n ; j++)
			if (j < n - i - 1)
				printf(" ");
			else
				printf("*");
		printf("\n");
	}
}