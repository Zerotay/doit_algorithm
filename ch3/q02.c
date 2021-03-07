#include "ch3.h"

int search(int a[], int n, int key)
{
	int i = -1;
	int j = 0;
	a[n] = key;

	printf("   |");
	while (++i < n)
		printf("%3d", i);
	printf("\n");
	printf("---+------------------------------------------------------------------------------\n");

	i = -1;
	while (1)
	{
		i++;
		printf("   |");
		for (j = 0; j < 3 * i + 2; j++)
			printf(" ");
		printf("*\n");
		printf("%3d|", i);
		for (j = 0; j < n; j++)
			printf("%3d", a[j]);
		printf("\n");
		if (a[i] == key)
			break ;
	}
	return i == n ? -1 : i;
}

int main(void)
{
	int check;
	int i, nx, ky, idx;
	int *x;

	srand(time(0));
	printf("-------------------------------------------------------\n");
	printf("-------------------------Q02---------------------------\n");
	printf("-------------------------------------------------------\n");
	puts("선형 검색(보초법)");
	printf("무작위 배열은 1, 아니면 직접 입력!\n무작위?\n");
	scanf("%d", &check);
	if (check == 1)
	{
		nx = rand() % 15 + 2;
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

	printf("\n\n검색 값 : ");
	scanf("%d", &ky);
	idx = search(x, nx, ky);

	if (idx == -1)
		puts("검색에 실패했습니다.");
	else
		printf("%d(은)는 x[%d]에 존재합니다.\n", ky, idx);

	free(x);

	return 0;
}