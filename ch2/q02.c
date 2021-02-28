#include "ch2.h"

int sumof(const int a[], int n)
{
	int	i;
	int sum = a[0];
	for (i = 1 ; i < n ; i++)
		sum += a[i];
	return (sum);
}