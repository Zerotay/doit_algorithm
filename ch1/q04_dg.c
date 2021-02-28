#include "ch1.h"

int med3(void)
{
	int a, b, c;
	int ans;

	printf("a 입력 : \n");
	scanf("%d", &a);
	printf("b 입력 : \n");
	scanf("%d", &b);
	printf("c 입력 : \n");
	scanf("%d", &c);

	if (a > b)
		if (b > c)
			ans = b;
		else
			if (c > a)
				ans = a;
			else
				ans = c;
	else
		if (a > c)
			ans = a;
		else
			if (c > b)
				ans = b;
			else
				ans = c;
	printf ("a,b,c : %d,%d,%d\nmed is %d\n", a,b,c,ans);
}