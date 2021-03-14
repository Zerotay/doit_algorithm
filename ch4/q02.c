#include "ch4.h"

void Printb(const IntStack *s)
{
	int i;

	for (i = s->max - 1; i >= s->ptr; i--)
		printf("%d ", s->stk[i]);
	putchar('\n');
}

int Searchb(const IntStack *s, int x)
{
	int i;

	for (i = s->ptr + 1; i < s->max; i++)
		if (s->stk[i] == x)
			return (s->max - 1 - i);
	return -1;
}

int main(void)
{
	IntStack s;
	int		size;
	int		a, b;

	printf("-------------------------------------------------------\n");
	printf("-------------------------Q02---------------------------\n");
	printf("-------------------------------------------------------\n");

	printf("공간을 공유하는 A, B 두 스택을 생성합니다.\n 총 스택 용량을 입력해주십시오\n");
	scanf("%d", &size);

	if (Initialize(&s, size) == -1) {
		puts("스택 생성에 실패하였습니다.");
		return 1;
	}

	a = 0;
	b = size - 1;
	while (1) {
		int menu, x, ret;

		printf("\n용량 : %d\n", Capacity(&s));
		printf("A 스택 데이터 개수 : %d\n", a);
		printf("B 스택 데이터 개수 : %d\n", size - 1 - b);

		printf("(11) A에 푸시 (12) A에서 팝 (13) A에서 피크\n");
		printf("(21) B에 푸시 (22) B에서 팝 (23) B에서 피크\n");
		printf("(4) 출력 (5) 클리어 (6) 데이터 검색\n");
		printf("(0) 종료 :\n");
		printf("a : %d b : %d\n", a, b);
		scanf("%d", &menu);
		if (menu == 0) break;

		switch (menu) {

		case 11:
			s.ptr = a;
			if (IsFull(&s))
			{
				printf("전체 스택 공간이 가득찼습니다.\n");
				break;
			}
			if (a > b && b != size)
			{
				printf("A 스택 공간이 가득 찼습니다. A스택에 데이터를 더 넣고 싶다면 B스택에서 팝하세요.\n");
				break;
			}
			printf("데이터 : ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a오류 : 푸시에 실패하였습니다.");
			a = s.ptr;
			break;

		case 21:
			s.ptr = b;
			if (b < 0)
			{
				printf("전체 스택 공간이 가득찼습니다.\n");
				break;
			}
			if (a > b && a)
			{
				printf("B 스택 공간이 가득 찼습니다. B스택에 데이터를 더 넣고 싶다면 A스택에서 팝하세요.\n");
				break;
			}
			printf("데이터 : ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a오류 : 푸시에 실패하였습니다.");
			b = s.ptr - 2;
			break;

		case 12:
			s.ptr = a;
			if (IsEmpty(&s))
				printf("A 스택에 데이터가 없습니다.\n");
			if (Pop(&s, &x) == -1)
				puts("\a오류 : 팝에 실패하였습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			a = s.ptr;
			break;


		case 22:
			s.ptr = b + 1;
			if (IsFull(&s))
			{
				printf("B 스택에 데이터가 없습니다.\n");
				break;
			}
			s.ptr = b + 2;
			Pop(&s, &x);
			printf("팝 데이터는 %d입니다.\n", x);
			b = s.ptr;
			break;

		case 13:
			s.ptr = a;
			if (IsEmpty(&s))
			{
				printf("A 스택에 데이터가 없습니다.\n");
				break;
			}
			if (Peek(&s, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 23:
			s.ptr = b + 1;
			if (IsFull(&s))
			{
				printf("B 스택에 데이터가 없습니다.\n");
				break;
			}
			s.ptr = b + 2;
			Peek(&s, &x);
			printf("피크 데이터는 %d입니다.\n", x);
			break;


		case 4:
			s.ptr = a;
			if (IsEmpty(&s))
				printf("A : 스택에 데이터가 없습니다.\n");
			else
			{
				printf("A : ");
				Print(&s);
			}
			s.ptr = b + 1;
			if (IsFull(&s))
				printf("B : 스택에 데이터가 없습니다.\n");
			else
			{
				printf("B : ");
				Printb(&s);
			}
			break;

		case 5:
			a = 0;
			b = size - 1;
			Clear(&s);
			break;

		case 6:
			printf("찾고자 하는 데이터를 입력해주십시오.\n");
			scanf("%d", &x);
			s.ptr = a;
			ret = Search(&s, x);
			if (ret == -1)
				printf("A : 해당 데이터는 스택에 없습니다.\n");
			else
				printf("A : 데이터 %d는 %d번째에 저장되어 있습니다.\n", x, ret + 1);
			s.ptr = b;
			ret = Searchb(&s, x);
			if (ret == -1)
				printf("B : 해당 데이터는 스택에 없습니다.\n");
			else
				printf("B : 데이터 %d는 %d번째에 저장되어 있습니다.\n", x, ret + 1);

			break;
		}
	}

	Terminate(&s);

	return 0;
}