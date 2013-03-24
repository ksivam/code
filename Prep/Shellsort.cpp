#include <stdio.h>

static int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
static int gapLength = 8;

int* createArray(int len)
{
	int* r = new int[len];

	for(int i = 0; i < len; ++i)
	{
		r[i] = len - i;
	}

	r[len/2] = 0;

	return r;
}


void printArray(int* a, int len)
{
	printf("\n");

	for(int i = 0 ; i < len; ++i)
	{
		printf("%d ", a[i]);
	}
}

void shellSort(int* a, int len)
{
	int hole;
	int item;

	for(int i = 0; i < gapLength; ++i)
	{
		for(int j = gaps[i]; j < len; ++j)
		{
			hole = j;
			item = a[hole];			
			while(hole > 0 && a[hole-1] > item)
			{
				a[hole] = a[hole-1];
				--hole;
			}
			a[hole] = item;
		}
	}
}

void main(int argc, char* argv[])
{
	int len = 10;
	int* arr = createArray(len);

	printArray(arr, len);
	shellSort(arr, len);
	printArray(arr, len);

	getchar();
}