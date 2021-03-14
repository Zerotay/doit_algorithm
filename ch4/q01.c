#include "ch4.h"

int main(void)
{
	IntStack s;
	int		size;

	printf("-------------------------------------------------------\n");
	printf("-------------------------Q01---------------------------\n");
	printf("-------------------------------------------------------\n");

	printf("스택을 생성합니다.\n스택 용량을 입력해주십시오\n");
	scanf("%d", &size);

	if (Initialize(&s, size) == -1) {
		puts("스택 생성에 실패하였습니다.");
		return 1;
	}

	while (1) {
		int menu, x, ret;

		printf("\n현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1) 푸시 (2) 팝 (3) 피크 (4) 출력\n");
		printf("(5) 클리어 (6) 데이터 검색\n");
		printf("(0) 종료 :\n");
		scanf("%d", &menu);
		if (menu == 0) break;

		switch (menu) {
		case 1: /*--- 푸시---*/
			if (IsFull(&s))
			{
				printf("스택 공간이 가득찼습니다.\n");
				break;
			}
			printf("데이터 : ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a오류 : 푸시에 실패하였습니다.");
			break;

		case 2: /*--- 팝 ---*/
			if (IsEmpty(&s))
				printf("스택에 데이터가 없습니다.\n");
			if (Pop(&s, &x) == -1)
				puts("\a오류 : 팝에 실패하였습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			break;

		case 3: /*--- 피크 ---*/
			if (IsEmpty(&s))
				printf("스택에 데이터가 없습니다.\n");
			if (Peek(&s, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 4: /*--- 출력 ---*/
			if (IsEmpty(&s))
			{
				printf("스택에 데이터가 없습니다.\n");
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
				printf("스택에 데이터가 없습니다.\n");
				printf("오류 : 검색에 실패하였습니다.\n");
				break;
			}
			printf("찾고자 하는 데이터를 입력해주십시오.\n");
			scanf("%d", &x);
			ret = Search(&s, x);
			if (ret == -1)
				printf("해당 데이터는 스택에 없습니다.\n");
			else
				printf("데이터 %d는 %d번째에 저장되어 있습니다.\n", x, ret + 1);
			break;
		}
	}

	Terminate(&s);

	return 0;
}