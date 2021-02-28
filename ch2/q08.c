#include "ch2.h"

void	ary_copy(int a[], const int b[], int n)
{
	for(int i = 0; i < n; i++)
		a[i] = b[i];
}