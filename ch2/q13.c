#include "ch2.h"

static int	mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static int	isleap(int	year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

static int dayofyear(int y, int m, int d)
{
	while (m)
		d += mdays[isleap(y)][m-- - 1];
	return (d);
}

Date DateOf(int y, int m, int d)
{
	Date	ret;

	ret.y = y;
	ret.m = m;
	ret.d = d;
	return (ret);
}

Date After(Date x, int n)
{
	int doy;
	int	i;
	int check;

	doy = dayofyear(x.y, x.m - 1, x.d);
	x.m = 1;
	doy += n;
	check = isleap(x.y) ? 366 : 365;
	while (doy > check)
	{
		doy -= check;
		x.y++;
	}
	while (doy > mdays[isleap(x.y)][x.m - 1])
		doy -= mdays[isleap(x.y)][x.m++ - 1];
	x.d = doy;
	return (x);
}

Date Before(Date x, int n)
{
	int doy;
	int	i;
	int check;

	doy = dayofyear(x.y, x.m - 1, x.d);
	x.m = 1;
	doy -= n;
	check = isleap(x.y) ? 366 : 365;
	while (doy <= 0)
	{
		check = isleap(--x.y) ? 366 : 365;
		doy += check;
	}
	while (doy > mdays[isleap(x.y)][x.m - 1])
		doy -= mdays[isleap(x.y)][x.m++ - 1];
	x.d = doy;
	return (x);
}