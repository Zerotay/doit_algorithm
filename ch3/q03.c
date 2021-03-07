#include "ch3.h"

int search_idx(int a[], int n, int key, int idx[])
{
	int i = -1;
	int ans = 0;

	a[n] = key;

	while (++i < n)
		if (a[i] == key)
			idx[ans++] = i;

	return (ans);
}

int main(void)
{
	int check;
	int i, nx, ky, idx;
	int *x;
	int	*arr;

	srand(time(0));
	printf("-------------------------------------------------------\n");
	printf("-------------------------Q03---------------------------\n");
	printf("-------------------------------------------------------\n");
	puts("선형 검색(보초법) 심화");
	printf("무작위 배열은 1, 아니면 직접 입력!\n무작위?\n");
	scanf("%d", &check);
	if (check == 1)
	{
		nx = rand() % 10 + 5;
		printf("요소의 개수 : %d\n", nx);
		x = calloc(nx + 1, sizeof(int));
		for (i = 0; i < nx; i++)
		{
			x[i] = rand() % 10 + 1;
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
	arr = calloc(nx + 1, sizeof(int));

	idx = search_idx(x, nx, ky, arr);

	if (!idx)
		puts("검색에 실패했습니다.");
	else
	{
		printf("\n%d의 값을 가진 요소 개수는 %d개\n", ky, idx);
		printf("해당 인덱스 : ");
		for (i = 0; i < idx; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}

	free(x);
	free(arr);

	return 0;
}