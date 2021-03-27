#include "ch4b.h"

typedef struct {
	int max;	/* 큐의 최대 용량 */
	int num;	/* 현재 요소의 개수 */
	int *que;	/* 큐의 첫 요소에 대한 포인터 */
} ArrayIntQueue;

int Arr_Initialize(ArrayIntQueue *q, int max)
{
	q->num = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

int Arr_Enque(ArrayIntQueue *q, int x)
{
	if (q->num >= q->max)
		return -1;
	else {
		q->que[q->num++] = x;
		return 0;
	}
}

int Arr_Deque(ArrayIntQueue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	else {
		*x = q->que[0];
		for (int i = 0; i < q->num - 1; i++)
		{
			q->que[i] = q->que[i + 1];
		}
		q->num--;
		return 0;
	}
}

int Arr_Peek(const ArrayIntQueue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[0];
	return 0;
}

void Arr_Clear(ArrayIntQueue *q)
{
	q->num = 0;
}

int Arr_Capacity(const ArrayIntQueue *q)
{
	return q->max;
}

int Arr_Size(const ArrayIntQueue *q)
{
	return q->num;
}

int Arr_IsEmpty(const ArrayIntQueue *q)
{
	return q->num <= 0;
}

int Arr_IsFull(const ArrayIntQueue *q)
{
	return q->num >= q->max;
}

int Arr_Search(const ArrayIntQueue *q, int x)
{
	int i;

	for (i = 0; i < q->num; i++) {
		if (q->que[i] == x)
			return i;
	}
	return -1;
}

void Arr_Print(const ArrayIntQueue *q)
{
	int i;

	for (i = 0; i < q->num; i++)
		printf("%d ", q->que[i]);
	putchar('\n');
}

void Arr_Terminate(ArrayIntQueue *q)
{
	if (q->que != NULL)
		free(q->que);
	q->max = q->num = 0;
}

int main(void)
{
	ArrayIntQueue s;
	int		size;

	printf("-------------------------------------------------------\n");
	printf("-------------------------Q03---------------------------\n");
	printf("-------------------------------------------------------\n");

	printf("큐를 생성합니다.\n큐 용량을 입력해주십시오\n");
	scanf("%d", &size);

	if (Arr_Initialize(&s, size) == -1) {
		puts("큐 생성에 실패하였습니다.");
		return 1;
	}

	while (1) {
		int menu, x, ret;

		printf("\n현재 데이터 수 : %d / %d\n", Arr_Size(&s), Arr_Capacity(&s));
		printf("(1) 인큐 (2) 디큐 (3) 피크 (4) 출력\n");
		printf("(5) 클리어 (6) 데이터 검색\n");
		printf("(0) 종료 :\n");
		scanf("%d", &menu);
		if (menu == 0) break;

		switch (menu) {
		case 1:
			if (Arr_IsFull(&s))
			{
				printf("큐 공간이 가득찼습니다.\n");
				break;
			}
			printf("데이터 : ");
			scanf("%d", &x);
			if (Arr_Enque(&s, x) == -1)
				puts("\a오류 : 인큐에 실패하였습니다.");
			break;

		case 2:
			if (Arr_IsEmpty(&s))
				printf("큐에 데이터가 없습니다.\n");
			if (Arr_Deque(&s, &x) == -1)
				puts("\a오류 : 디큐에 실패하였습니다.");
			else
				printf("디큐된 데이터는 %d입니다.\n", x);
			break;

		case 3: /*--- 피크 ---*/
			if (Arr_IsEmpty(&s))
				printf("스택에 데이터가 없습니다.\n");
			if (Arr_Peek(&s, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 4: /*--- 출력 ---*/
			if (Arr_IsEmpty(&s))
			{
				printf("큐에 데이터가 없습니다.\n");
				printf("오류 : 출력에 실패하였습니다.\n");
			}
			else
				Arr_Print(&s);
			break;

		case 5:
			Arr_Clear(&s);
			break;

		case 6:
			if (Arr_IsEmpty(&s))
			{
				printf("큐에 데이터가 없습니다.\n");
				printf("오류 : 검색에 실패하였습니다.\n");
				break;
			}
			printf("찾고자 하는 데이터를 입력해주십시오.\n");
			scanf("%d", &x);
			ret = Arr_Search(&s, x);
			if (ret == -1)
				printf("해당 데이터는 큐에 없습니다.\n");
			else
				printf("데이터 %d는 배열의 %d번째에 저장되어 있습니다.\n", x, ret + 1);
			break;
		}
	}

	Arr_Terminate(&s);

	return 0;
}
