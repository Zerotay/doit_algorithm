#include "ch2.h"

void	shuffle(int a[], int n)
{
	int	tmp;
	srand(time(0));
	for(int i = 0; i < n; i++)
	{
		tmp = rand() % n;
		swap(int, a[i], a[tmp]);
	}
}