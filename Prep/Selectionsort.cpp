//#include <stdio.h>
//
//int* createArray(int len)
//{
//	int* ret = new int[len];
//
//	for(int i = 0; i < len; ++i)
//	{
//		ret[i] = len - i;
//	}
//
//	return ret;
//}
//
//void printArray(int* arr, int len)
//{
//	printf("\n");
//
//	for(int i = 0; i < len; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void swap(int* a, int* b)
//{
//	int t = *b;
//	*b = *a;
//	*a = t;
//}
//
//void selectionSort(int* a, int len)
//{
//	int index = 0;
//	int min = 0;
//
//	while(index < len -1)
//	{
//		min = index;
//		for(int i = index + 1; i < len; ++i)
//		{
//			if(a[i] < a[min])
//			{
//				min = i;
//			}
//		}
//
//		swap(a + min, a + index);
//		++index;
//	}
//}
//
//
//void main(int argc, char* argv[])
//{
//	int len = 5;
//	int* arr = createArray(len);
//
//	printArray(arr, len);
//	selectionSort(arr, len);
//	printArray(arr, len);
//
//	getchar();
//}