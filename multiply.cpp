// stdafx.cpp : source file that includes just the standard includes
// practice.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file


int sum = 0;

int add_bit(int a, int b)
{
	int temp_a = a, temp_b=b,k=1, carry_in=0,carry_out=0, sum_val=0;
	while (temp_a || temp_b)
	{
		int ak = a&k, bk = b&k;
		carry_out = (ak&bk) | (ak&carry_in) | (bk&carry_in);
		sum_val |= (ak^bk^carry_in);
		k <<= 1, carry_in= carry_out<< 1, temp_a>>=1, temp_b >>= 1;
	}

	return sum_val;
}
int mult(int x, int y)
{
	while (x)
	{
		if (x & 0x01)
			sum=add_bit(sum,y);
		x >>= 1;
		y <<= 1;
	}
	return sum;
}

int main()
{
	int x = 5;
	int y = 10;
	printf("%d\n", mult(x, y));
	return 0;
}