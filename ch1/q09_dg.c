#include "ch1.h"

int sumof(int a, int b)
{
	int sum = 0;

	if (a > b)
		while (a >= b)
			sum += b++;
	else
		while (b >= a)
			sum += a++;
	return (sum);
}