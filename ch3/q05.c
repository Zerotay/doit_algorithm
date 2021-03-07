#include "ch3.h"

int bin_search2(int a[], int n, int key)
{
	int start;
	int end;
	int mid;
	int i = -1;
	int j;

	start = 0;
	end = n - 1;
	for (i = 0; i < n; i++)
	{
		mid = (start + end) / 2;
		if (a[mid] == key)
		{
			while(a[mid] == key)
				mid--;
			return (++mid);
		}
		else if (a[mid] < key)
			start = mid + 1;
		else
			end = mid - 1;
		if (start > end)
			break;
	}
	return (-1);
}

int main(void)
{
	int check;
	int i, nx, ky, idx;
	int *x;

	srand(time(0));
	printf("-------------------------------------------------------\n");
	printf("-------------------------Q05---------------------------\n");
	printf("-------------------------------------------------------\n");
	puts("이진검색");
	printf("무작위 배열은 1, 아니면 직접 입력!\n무작위?\n");
	scanf("%d", &check);
	if (check == 1)
	{
		nx = rand() % 15 + 4;
		printf("요소의 개수 : %d\n", nx);
		x = calloc(nx + 1, sizeof(int));
		for (i = 0; i < nx; i++)
		{
			if (!i)
				x[i] = rand() % 5;
			else
				x[i] = x[i - 1] + rand() % 3;
			printf ("| x[%d] : %d |", i, x[i]);
		}
	}
	else
	{
		printf("요소의 개수 : ");
		scanf("%d", &nx);
		x = calloc(nx + 1, sizeof(int));
		for (i = 0; i < nx; i++) {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		}
	}

	printf("\n검색 값 : ");
	scanf("%d", &ky);
	idx = bin_search2(x, nx, ky);

	if (idx == -1)
		puts("검색에 실패했습니다.");
	else
		printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);

	free(x);

	return 0;
}