#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
//int main()
//{
//	int* p = (int*)malloc(40);//����ռ�
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
//	free(p);//�ͷ�p��������ڴ�ռ�
//	p = NULL;//������ʹ��p��ָ���ڴ�ռ䣬�����ڴ��ͻ����ͬ
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
	int* ptr = (int*)ralloc(p, 80);//��realloc����ʧ�ܵ��ǣ����ص���NULL
	if (ptr != NULL)
	{
		p = ptr;
		ptr = NULL;
	}
	for (int i = 10; i < 20; i++)
	{
				*(p + i) = i;
	}
	//�ͷ�
	free(p);
	p = NULL;
	return 0;
}