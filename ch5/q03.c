#include "ch5.h"

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int	gcd_array(const int a[], int n)
{
	// int ret;
	// ret = gcd(a[--n], a[--n]);
	// // 이거 왜 두번재 쪽을 --n이 아니라 n-1로 하면 제대로 반영이 안되지?
	// while (n)
	// 	ret = gcd(ret, a[--n]);
	// return (ret);

	if (n == 0)
		return a[0];
	else
		return gcd(a[n], gcd_array(a, n-1));
}

int main(void)
{
	int x, y;
	int size;
	int *arr;

	puts("배열의 크기를 2 이상으로 정하세요.");
	scanf("%d", &size);
	if (!(arr = calloc(size, sizeof(int))))
		return (0);
	printf("배열에 값을 넣어주세요.\n");
	for(int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n배열의 최대공약수는 %d입니다.\n", gcd_array(arr, size));
	free(arr);
	return 0;
}