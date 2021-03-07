#include "ch3.h"

int long_cmp(const long *a, const long *b)
{
	if (*a > *b)
		return -1;
	else if (*a < *b)
		return 1;
	else
		return 0;
}

int main(void)
{
	int check;
	int i, nx;
	long	key;
	long *x;
	long *p;

	srand(time(0));
	printf("-------------------------------------------------------\n");
	printf("-------------------------Q06---------------------------\n");
	printf("-------------------------------------------------------\n");

	puts("bsearch 함수를 사용하여 검색\n");
	printf("무작위 배열은 1, 아니면 직접 입력!\n무작위?\n");
	scanf("%d", &check);

	if (check == 1)
	{
		nx = rand() % 15 + 4;
		printf("요소의 개수 : %d\n", nx);
		x = calloc(nx + 1, sizeof(long));
		for (i = 0; i < nx; i++)
		{
			if (!i)
				x[i] = rand() % 50 + nx;
			else
				x[i] = x[i - 1] - rand() % 5;
			printf ("| x[%d] : %ld |", i, x[i]);
		}
	}
	else
	{
		printf("요소의 개수 : ");
		scanf("%d", &nx);
		x = calloc(nx, sizeof(int));

		printf("내림차순으로 입력하세요.\n");
		printf("x[0] : ");
		scanf("%ld", &x[0]);
		for (i = 1; i < nx; i++) {
			do {
				printf("x[%d] : ", i);
				scanf("%ld", &x[i]);
			} while (x[i] > x[i - 1]);
		}
	}



	printf("\n검색 값 : ");
	scanf("%ld", &key);
	p = bsearch(&key, x, nx, sizeof(long), (int(*)(const void *, const void *)) long_cmp);

	if (p == NULL)
		puts("검색에 실패했습니다.\n");
	else
		printf("%ld는 x[%ld]에 있습니다.\n", key, (long)(p - x));

	free(x);

	return 0;
}