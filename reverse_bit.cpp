// reverse_bit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#define SIZE_INT sizeof(0)*8

typedef unsigned int uint;

int swapbits(int num, int i, int j)
{
	int a = ((num >> i) & 1);
	int b = ((num >> j) & 1);
	if (a^b)
		num ^= ((1 << i) | (1 << j));
	return num;
}

int reverse_bit1(int num)
{
	int size = sizeof(num) * 8;
	//convert 11001001 to 10010011 
	for (int i = 0; i < size / 2; i++)
	{
		num = swapbits(num, size - 1 - i, i);
	}
	return num;
}

int reverse_bit2(int num)
{
	assert(sizeof(num) == 4);
	num = ((num & 0x55555555) << 1 | (num & 0xAAAAAAAA) >> 1);
	num = ((num & 0x33333333) << 2 | (num & 0xCCCCCCCC) >> 2);
	num = ((num & 0x0F0F0F0F) << 4 | (num & 0xF0F0F0F0) >> 4);
	num = ((num & 0x00FF00FF) << 8 | (num & 0xFF00FF00) >> 8);
	num = ((num & 0x0000FFFF) << 16 | (num & 0xFFFF0000) >> 16);
	return num;
}

int main()
{
	uint num = 1;
	printf("%d\n", reverse_bit1(num));
	printf("%d\n", reverse_bit2(num));

	return 0;
}

