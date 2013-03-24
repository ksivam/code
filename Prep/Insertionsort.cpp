//#include <stdio.h>
//
//int* createArray(int len)
//{
//	int* r = new int[len];
//
//	for(int i = 0; i < len; ++i)
//	{
//		r[i] = len -i;
//	}
//
//	r[len/2] = 0;
//
//	return r;
//}
//
//void printArray(int* a, int len)
//{
//	printf("\n");
//
//	for(int i = 0; i < len ; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//}
//
//void insertionSort(int* a, int len)
//{
//	int hole = 0;
//	int item;
//	for(int i = 1; i < len; ++i)
//	{
//		hole = i;
//		item = a[hole];
// 		while(hole > 0 && a[hole-1] > item)
//		{
//			a[hole] = a[hole-1];
//			--hole;
//		}
//		a[hole] = item;
//	}
//}
//
//void main(int argc, char* argv[])
//{
//	int len = 10;
//	int* arr = createArray(len);
//
//	printArray(arr, len);
//	insertionSort(arr, len);
//	printArray(arr, len);
//
//	getchar();
//}