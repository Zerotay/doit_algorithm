#include "ch1.h"

int min4(int a, int b, int c, int d)
{
	if (a > b)
		a = b;
	if (c > d)
		c = d;
	if (a > c)
		a = c;
	return (a);
}