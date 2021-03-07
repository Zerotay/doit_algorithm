#include "ch3.h"

int int_cmp(const int *a, const int *b)
{
	if (*a > *b)
		return -1;
	else if (*a < *b)
		return 1;
	else
		return 0;
}

void	*binsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
	int	i;
	int tmp;
	void *save;
	void *start;
	void *end;
	void *mid;

	start = (void *)base;
	end = (void *)(base) + (nmemb * size - size) ;
	while (start <= end)
	{
		i = 0;
		save = start;
		while (save != end)
		{
			save += size;
			i++;
		}
		mid = start + ((i / 2) * size);
		tmp = (*compar)(mid, key);
		if (tmp == 1)
			end = mid - size;
		else if (tmp == -1)
			start = mid + size;
		else
			return ((void *)mid);
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
	printf("-------------------------Q08---------------------------\n");
	printf("-------------------------------------------------------\n");

	puts("binsearch 함수를 사용하여 검색\n");
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
				x[i] = rand() % 50 + nx;
			else
				x[i] = x[i - 1] - rand() % 5;
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

	p = binsearch(&key, x, nx, sizeof(int), (int(*)(const void *, const void *)) int_cmp);

	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 x[%d]에 있습니다.\n", key, (int)(p - x));

	free(x);

	return 0;
}