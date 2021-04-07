#include "ch5.h"

int factorial(int n)
{
	int ret;

	ret = 1;
	while (n)
		ret *= n--;
	return (ret);
}
int main(void)
{
	int x;
	printf("정수를 입력하세요. : ");
	scanf("%d", &x);

	printf("%d의 순차곱셈 값은 %d입니다.\n", x, factorial(x));

	return 0;
}