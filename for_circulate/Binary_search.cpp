#include<stdio.h>
#include<stdlib.h>
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void binary_search(int* arr, int n, int num)
{
	int max = n;
	int min = 0;
	while (min <= max)
	{
		int mid = (min + max) / 2;
		if (arr[mid] == num)
		{
			printf("找到了！下标为%d\n", mid);
			return ;
		}
		else if (arr[mid] <num)
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
	}
	printf("数组中没有您要查找的元素!\n");
}
//int main()
//{
//	int arr[10] = { 2,3,1,4,8,0,12,11,21,22 };
//	qsort(arr,10,sizeof(arr[0]),cmp_int);
//	for (int i=0 ; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	binary_search(arr, 10,8);
//	return 0;
//
//}