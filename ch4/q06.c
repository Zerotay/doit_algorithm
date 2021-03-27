#include "ch4b.h"

int Back_Enque(IntQueue *q, int x)
{
	if (q->num >= q->max)
		return -1;
	else {
		q->num++;
		if (q->front == 0)
			q->front = q->max;
		q->que[--q->front] = x;
		return 0;
	}
}

int Back_Deque(IntQueue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	else {
		q->num--;
		if (q->rear == 0)
			q->rear = q->max;
		*x = q->que[--q->rear];
		return 0;
	}
}

int Back_Peek(const IntQueue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[(q->max + q->rear - 1) % q->max];
	return 0;
}


int main()
{
	IntQueue s;
	int		size;

	printf("-------------------------------------------------------\n");
	printf("-------------------------Q06---------------------------\n");
	printf("-------------------------------------------------------\n");

	printf("큐를 생성합니다.\n큐 용량을 입력해주십시오\n");
	scanf("%d", &size);

	if (Initialize(&s, size) == -1) {
		puts("큐 생성에 실패하였습니다.");
		return 1;
	}

	while (1) {
		int menu, x, ret;

		printf("\n현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1) 인큐 (11) 리버스_인큐 (2) 디큐 (22) 리버스_디큐\n");
		printf("(3) 피크 (33) 리버스_피크 (4) 출력\n");
		printf("(5) 클리어 (6) 데이터 검색\n");
		printf("(0) 종료 :\n");
		scanf("%d", &menu);
		if (menu == 0) break;

		switch (menu) {
		case 1:
			if (IsFull(&s))
			{
				printf("큐 공간이 가득찼습니다.\n");
				break;
			}
			printf("데이터 : ");
			scanf("%d", &x);
			if (Enque(&s, x) == -1)
				puts("\a오류 : 인큐에 실패하였습니다.");
			break;

		case 11:
			if (IsFull(&s))
			{
				printf("큐 공간이 가득찼습니다.\n");
				break;
			}
			printf("데이터 : ");
			scanf("%d", &x);
			if (Back_Enque(&s, x) == -1)
				puts("\a오류 : 인큐에 실패하였습니다.");
			break;

		case 2:
			if (IsEmpty(&s))
				printf("큐에 데이터가 없습니다.\n");
			if (Deque(&s, &x) == -1)
				puts("\a오류 : 디큐에 실패하였습니다.");
			else
				printf("디큐된 데이터는 %d입니다.\n", x);
			break;

		case 22:
			if (IsEmpty(&s))
				printf("큐에 데이터가 없습니다.\n");
			if (Back_Deque(&s, &x) == -1)
				puts("\a오류 : 디큐에 실패하였습니다.");
			else
				printf("디큐된 데이터는 %d입니다.\n", x);
			break;

		case 3: /*--- 피크 ---*/
			if (IsEmpty(&s))
				printf("스택에 데이터가 없습니다.\n");
			if (Peek(&s, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 33: /*--- 피크 ---*/
			if (IsEmpty(&s))
				printf("스택에 데이터가 없습니다.\n");
			if (Back_Peek(&s, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 4: /*--- 출력 ---*/
			if (IsEmpty(&s))
			{
				printf("큐에 데이터가 없습니다.\n");
				printf("오류 : 출력에 실패하였습니다.\n");
			}
			else
				Print(&s);
			break;

		case 5:
			Clear(&s);
			break;

		case 6:
			if (IsEmpty(&s))
			{
				printf("큐에 데이터가 없습니다.\n");
				printf("오류 : 검색에 실패하였습니다.\n");
				break;
			}
			printf("찾고자 하는 데이터를 입력해주십시오.\n");
			scanf("%d", &x);
			ret = Search(&s, x);
			if (ret == -1)
				printf("해당 데이터는 큐에 없습니다.\n");
			else
			{
				printf("데이터 %d는 배열의 %d번째에 저장되어 있습니다.\n", x, ret + 1);
				// printf("큐 내부 순서 상으로는 %d번째에 위치해 있습니다.\n", Search2(&s, x) + 1);

			}
			break;
		}
	}

	Terminate(&s);

}