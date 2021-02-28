#include "ch2.h"

int	card_conv(unsigned x, int n, char d[])
{
	char	dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int		digits = 0;

	if (x == 0)
		d[digits++] = dchar[0];
	else
		while (x)
		{
			d[digits++] = dchar[x % n];
			printf("%2d|%10d ... %X\n", n, x, x % n);
			printf("  +----------\n");
			x /= n;
		}
	printf("%13d\n", 0);
	for (int i = 0 ; i < digits / 2 ; i++)
		swap(int, d[i], d[digits - i - 1]);
	return (digits);
}