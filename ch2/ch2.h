#ifndef CH2_H
# define CH2_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)

typedef struct {
	int y;
	int m;
	int d;
} Date;


int		minof(const int a[], int n);
int		sumof(const int a[], int n);
double	aveof(const int a[], int n);
int q4(void);

void	ary_reverse(int a[], int n);

int	card_conv(unsigned x, int n, char d[]);

void	ary_copy(int a[], const int b[], int n);
void	ary_rcopy(int a[], const int b[], int n);
void	shuffle(int a[], int n);

int	q11(void);
int q12(void);

Date DateOf(int y, int m, int d);
Date After(Date x, int n);
Date Before(Date x, int n);

#endif