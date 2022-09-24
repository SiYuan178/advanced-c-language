#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
//int main()
//{
//	int* p = (int*)malloc(40);//申请空间
//	if (p == NULL)
//	{
//		printf("%s", strerror(errno));
//	}
//	int* ptr = p;
//	for (int i = 0; i < 10; i++)
//	{
//		*ptr = i;
//		ptr++;
//	}
//	free(p);//释放p所申请的内存空间
//	p = NULL;//避免误使用p所指的内存空间，发生内存冲突，下同
//	ptr = NULL;
//	return 0;
//}
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//		{
//		printf("%s", strerror(errno));
//		}
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
int main()
{
	int* p = (int*)malloc(40);
	int* ptr = (int*)ralloc(p, 80);//当realloc开辟失败的是，返回的是NULL
	if (ptr != NULL)
	{
		p = ptr;
		ptr = NULL;
	}
	for (int i = 10; i < 20; i++)
	{
				*(p + i) = i;
	}
	//释放
	free(p);
	p = NULL;
	return 0;
}