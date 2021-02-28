#include "ch2.h"

void	ary_rcopy(int a[], const int b[], int n)
{
	for(int i = 0; i < n; i++)
		a[i] = b[n - i - 1];
}