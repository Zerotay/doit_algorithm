#include "ch2.h"


double	aveof(const int a[], int n)
{
	int	i;
	double ave = a[0];
	for (i = 1 ; i < n ; i++)
		ave += a[i];
	return (ave / n);
}