#include "ch3.h"

int int_cmp(const int *a, const int *b)
{

	if (*a == *b)
		return (1);
	else
		return (0);
}

void	*seqsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
	size_t	i;

	i = -1;
	while (++i < nmemb)
	{
		if ((*compar)(base, key))
			return ((void *)base);
		base += size;
	}
	return (NULL);
}

int main(void)
{
	int check;
	int i, nx;
	int	key;
	int *x;
	int *p;

	srand(time(0));
	printf("-------------------------------------------------------\n");
	printf("-------------------------Q07---------------------------\n");
	printf("-------------------------------------------------------\n");

	puts("seqsearch 함수를 사용하여 검색\n");
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
		x = calloc(nx, sizeof(int));

		printf("내림차순으로 입력하세요.\n");
		printf("x[0] : ");
		scanf("%d", &x[0]);
		for (i = 1; i < nx; i++) {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		}
	}
	printf("\n검색 값 : ");
	scanf("%d", &key);

	p = seqsearch(&key, x, nx, sizeof(int), (int(*)(const void *, const void *)) int_cmp);

	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 x[%d]에 있습니다.\n", key, (int)(p - x));

	free(x);

	return 0;
}