#ifndef CH4B_H
#define CH4B_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int max;	/* 큐의 최대 용량 */
	int num;	/* 현재 요소의 개수 */
	int front;	/* 프런트 */
	int rear;	/* 리어 */
	int *que;	/* 큐의 첫 요소에 대한 포인터 */
} IntQueue;


int Initialize(IntQueue *q, int max);

int Enque(IntQueue *q, int x);

int Deque(IntQueue *q, int *x);

int Peek(const IntQueue *q, int *x);

void Clear(IntQueue *q);

int Capacity(const IntQueue *q);

int Size(const IntQueue *q);

int IsEmpty(const IntQueue *q);

int IsFull(const IntQueue *q);

int Search(const IntQueue *q, int x);

void Print(const IntQueue *q);

void Terminate(IntQueue *q);


int	Search2(const IntQueue *q, int x);
#endif