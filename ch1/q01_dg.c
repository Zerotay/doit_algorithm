#include "ch1.h"

int	max4(int a, int b, int c, int d)
{
	if (a < b)
		a = b;
	if (a < c)
		a = c;
	if (a < d)
		a = d;
	return (a);
}