//#include <stdio.h>
//
////////////////////////
///*
//Quicksort stratergy
//1. Partition the list to get a pivot "i" such that, a[i] finds its final state ie
//	i) a[l] ...... a[i-1] < a[i]
//	ii) a[i+1] ..... a[r] > a[i]
//2. divide the list on the pivot into smaller part and greater part
//3. Apply step 1 and 2 to smaller and greater part, till the parts size becomes <=1
//*/
////////////////////////////
//
//int* createArray(int len)
//{
//	int* arr = new int[len];
//
//	for(int i=0; i < len; ++i)
//	{
//		arr[i] = len - i; 
//	}
//
//	return arr;
//}
//
//void printArray(int* arr, int len)
//{
//	printf("\n ");
//	for(int i = 0; i < len; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void swap(int* a, int* b)
//{
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//
//int partition(int* a, int l, int r)
//{
//	int v = a[r];
//	int i = l - 1;
//	int j = r;
//
//	while(true)
//	{
//		// scan from left to right to find the element"s position which is out of 
//		// its position ie greater than the pivot element "v"
//		while(a[++i]  < v);
//
//		// scan from right to left to find the element"s position which is out of 
//		// its position ie lesser than the pivot element "v"
//		while(a[--j] > v)
//		{
//			if(j <= l) // check whether right -> left reached starting index
//				break;
//		}
//
//		if( i >= j)
//			break;
//
//		// swap the out of place elements
//		swap(a + i, a + j);
//	}
//
//	// place the pivot element in its final position, ST
//	//	i) a[l] ...... a[i-1] < a[i]
//	// ii) a[i+1] ..... a[r] > a[i]
//	swap(a + i, a + r);
//
//	// return pivot index
//	return i;
//}
//
//void Quicksort(int* arr, int l, int r)
//{
//	if( r <= l)
//		return;
//
//	// get the pivot after placing arr[i] in its final position
//	int i = partition(arr, l, r);
//
//	// partition the smaller part
//	Quicksort(arr, l, i - 1);
//
//	// partition the greater part
//	Quicksort(arr, i + 1, r);
//	
//}
//
//
//void main(int argc, char* argv[])
//{
//	int len = 10;
//	int l = 0;
//	int r = len-1;
//	int* arr = createArray(len);
//
//	printArray(arr, len);
//	Quicksort(arr, l, r);
//	printArray(arr, len);
//
//	getchar();
//}