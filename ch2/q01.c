#include "ch2.h"

int minof(const int a[], int n)
{
	int	i;
	int min = a[0];
	for (i = 1 ; i < n ; i++)
		if (a[i] < min)
			min = a[i];
	return (min);
}