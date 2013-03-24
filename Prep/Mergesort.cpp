//#include <stdio.h>
//
//int* createArray(int len)
//{
//	int* ret = new int[len + 1];
//
//	for(int i = 0; i < len; ++i)
//	{
//		ret[i] = len - i;
//	}
//
//	// add a null pointer
//	ret[len+1] = "\0";
//
//	return ret;
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
//int arraylength(int* a)
//{
//	int len = 0;
//
//	while(a[len++] != "\0");
//
//	return len-1;
//}
//
//int* merge(int* la, int* ra)
//{
//	int ll = arraylength(la);
//	int rl = arraylength(ra);
//	int* ret = new int[ll+rl + 1];
//	ret[ll + rl] = "\0";
//	int l = 0, r = 0, i = 0;
//
//	while(l < ll || r < rl)
//	{
//		if(r < rl && l < ll)
//		{
//			if(ra[r] < la[l])
//				ret[i++] = ra[r++];
//			else
//				ret[i++] = la[l++];
//		} else if(l < ll)
//		{
//			ret[i++] = la[l++];
//		} else if(r < rl)
//		{
//			ret[i++] = ra[r++];
//		}
//	}
//
//	return ret;
//}
//
//int* mergeSort(int* a, int l, int r)
//{
//	if( r <= l)
//	{
//		int* ret = new int[2];
//		ret[0] = a[l];
//		ret[1] = "\0";
//		return ret;
//	}
//
//	int m = (r-l) / 2;
//	int* left = mergeSort(a, l, (l + m));
//	int* right = mergeSort(a, ((m+1) + l), r);
//
//	return merge(left, right);
//}
//
//void main(int argc, char* argv[])
//{
//	int len = 6;
//	int l = 0;
//	int r = len-1;
//	int* arr = createArray(len);
//
//	printArray(arr, len);
//	int* result = mergeSort(arr, l, r);
//	printArray(result, len);
//
//	getchar();
//}