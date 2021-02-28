#include "ch2.h"

int q4(void)
{
	int ans;

	srand(time(0));
	ans = rand() % 16 + 5;
	return (ans);
}