#include "ch2.h"

int	maxof(const int a[], int n )
{
	int	i;
	int max = a[0];
	for (i = 1 ; i < n ; i++)
		if (a[i] > max)
			max = a[i];
	return (max);
} // q1-4

int	main()
{

// q1-4
	// int	i;
	// int *height;
	// int	number;

	// srand(time(0));

	// // // q4
	// number = q4();

	// height = calloc(number, sizeof(int));
	// printf("사람 수 : %d\n", number);

	// for (i = 0 ; i < number ; i++)
	// {
	// 	height[i] = rand() % 90 + 100;
	// 	printf("height[%d] = %d\n", i, height[i]);
	// }
	// printf("최댓값은 %d입니다.\n", maxof(height, number));

	// // // // q1
	// printf("최솟값은 %d입니다.\n", minof(height, number));

	// // // // q2
	// printf("합계는 %d입니다.\n", sumof(height, number));

	// // // // q3
	// printf ("평균은 %f입니다.\n", aveof(height, number));

	// free(height);

// q5
	// int	i;
	// int	*x;
	// int	nx;

	// printf("요소 개수 : ");
	// scanf("%d", &nx);
	// x = calloc(nx, sizeof(int));
	// printf("%d개의 정수를 입력하세요.\n", nx);

	// for (i = 0; i < nx; i++)
	// {
	// 	printf("x[%d] : ", i);
	// 	scanf("%d", &x[i]);
	// }
	// ary_reverse(x, nx);
	// printf("배열의 요소를 역순으로 정렬했습니다.\n");
	// for (i = 0; i < nx; i++)
	// 	printf("x[%d] = %d\n", i, x[i]);
	// free(x);

// q6-7
	// int			i;
	// unsigned	no;
	// int			cd;
	// int			dno;
	// char		cno[512];
	// int			retry;

	// printf("10진수를 기수 변환합니다.");
	// do
	// {
	// 	printf("변환하는 음이 아닌 정수 : ");
	// 	scanf("%u", &no);
	// 	do
	// 	{
	// 		printf("어떤 진수로 변환할까요?(2-36) : ");
	// 		scanf("%d", &cd);
	// 	} while (cd < 2 || cd > 36);
	// 	dno = card_conv(no, cd, cno);

	// 	printf("%d진수로는", cd);
	// 	for (i = 0 ; i < dno ; i++)
	// 		printf("%c", cno[i]);
	// 	printf("입니다.\n");
	// 	printf("한 번 더 할까요?(1 ... 예/0 ... 아니오) : ");
	// 	scanf("%d", &retry);
	// } while (retry == 1);


// q8
	// int	*a;
	// int	*b;
	// int	n;

	// srand(time(0));
	// n = rand() % 10;
	// printf("요소 개수 : %d\n", n);

	// if (!(b = calloc(n, sizeof(int))) || !(a = calloc(n, sizeof(int))))
	// 	return (0);

	// for (int i = 0 ; i < n ; i++)
	// {
	// 	b[i] = rand() % 90;
	// 	printf("b[%d] = %d\n", i, b[i]);
	// }

	// ary_copy(a, b, n);

	// printf("a 배열 요소들\n");
	// for (int i = 0; i < n ; i++)
	// 	printf("%d ", a[i]);
	// printf("\n");
	// free(a);
	// free(b);


// q9
	// int	*a;
	// int	*b;
	// int	n;

	// srand(time(0));
	// n = rand() % 10;
	// printf("요소 개수 : %d\n", n);

	// if (!(b = calloc(n, sizeof(int))) || !(a = calloc(n, sizeof(int))))
	// 	return (0);

	// for (int i = 0 ; i < n ; i++)
	// {
	// 	b[i] = rand() % 90;
	// 	printf("b[%d] = %d\n", i, b[i]);
	// }

	// ary_rcopy(a, b, n);

	// printf("a 배열 요소들\n");
	// for (int i = 0; i < n ; i++)
	// 	printf("%d ", a[i]);
	// printf("\n");
	// free(a);
	// free(b);


// q10
	// int	*b;
	// int	n;

	// srand(time(0));
	// n = rand() % 10 + 2;
	// printf("요소 개수 : %d\n", n);

	// if (!(b = calloc(n, sizeof(int))))
	// 	return (0);

	// for (int i = 0 ; i < n ; i++)
	// {
	// 	b[i] = i;
	// 	printf("b[%d] = %d\n", i, b[i]);
	// }

	// shuffle(b, n);

	// printf("뒤섞인 결과!\n");
	// for (int i = 0; i < n ; i++)
	// 	printf("%d ", b[i]);
	// printf("\n");
	// free(b);

// // q11
// 	q11();

// q12
	// q12();

// q13
	Date d;
	Date ans;
	int n;

	srand(time(0));
	d.y = rand() % 200 + 2000;
	d.m = rand() % 12 + 1;
	d.d = rand() % 31 + 1;
	while (d.m == 2 && d.d > 28)
		d.d = rand() % 31 + 1;
	while ((d.m == 4 || d.m == 6 || d.m == 9 || d.m == 11) && d.d == 31)
		d.d = rand() % 31 + 1;
	printf ("할당된 날짜 ");
	printf ("%d년 ", d.y);
	printf ("%d월 ", d.m);
	printf ("%d일\n", d.d);

	ans = DateOf(d.y, d.m, d.d);
	printf ("Dateof이 받은 날짜 ");
	printf ("%d년 ", ans.y);
	printf ("%d월 ", ans.m);
	printf ("%d일\n", ans.d);

	n = rand() % 500 + 1;
	ans = After(d, n);
	printf ("%d일 뒤는?\n", n);
	printf ("%d년 ", ans.y);
	printf ("%d월 ", ans.m);
	printf ("%d일\n", ans.d);

	n = rand() % 500 + 1;
	ans = Before(d, n);
	printf ("%d일 전은?\n", n);
	printf ("%d년 ", ans.y);
	printf ("%d월 ", ans.m);
	printf ("%d일\n", ans.d);

	return (0);
}