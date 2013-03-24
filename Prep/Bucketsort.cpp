//#include <stdio.h>
//
//int* createArray(int len)
//{
//	int* r = new int[len];
//	for(int  i =0 ; i < len; ++i)
//	{
//		r[i] = len - i;
//	}
//
//	r[len/2] = 10;
//
//	return r;
//}
//
//void printArray(int* a, int len)
//{
//	printf("\n");
//	for(int i = 0; i < len; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//}
//
//int* createBucket(int range)
//{
//	int* r = new int[range];
//	for(int i =0 ; i < range; ++i)
//	{
//		r[i] = 0;
//	}
//	
//	return r;
//}
//
//void bucketSort(int* arr, int len, int range)
//{
//	int* bucket = createBucket(range);
//
//	for(int i=0; i< len; ++i)
//	{
//		++bucket[arr[i]];
//	}
//
//	for(int i = 0, j = 0; j < range; ++j)
//	{
//		for(int k = bucket[j]; k > 0; --k)
//		{
//			arr[i++] = j;
//		}
//	}
//}
//
//void main(int argc, char* argv[])
//{
//	int len = 10;
//	int* arr = createArray(len);
//
//	printArray(arr, len);
//	bucketSort(arr, len, len + 1);
//	printArray(arr, len);
//
//	getchar();
//}