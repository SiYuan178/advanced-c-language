#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void menu()
{
	printf("****************************************\n");
	printf("****1.Add                2.Sub**********\n");
	printf("****3.Mul                4.Div**********\n");
	printf("****0.exit                   ***********\n");
	printf("****************************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	if (y == 0)
	{
		printf("��������Ϊ0\n");
	}
	else
	{
		return x / y;
	}
}
int main()
{
	int x, y;
	int option;
	int(*ptr[])(int, int) = { 0,Add,Sub,Mul,Div };
	do
	{
		menu();
		printf("������Ҫ���е����㣺");
		scanf("%d", &option);
		if (option == 0)
		{
			printf("�˳��ɹ���\n");
			return 0;
		}
		if (option >= 1 && option <= 4)
		{
			printf("��������������");
			scanf("%d%d", &x, &y);
			int ret = ptr[option](x,y);
			if (option == 4 && y == 0)
			{
				;
			}
			else
			{
			printf("������Ϊ��%d\n", ret);
			}
			
		}
		else
		{
			printf("����������������������!\n");
		}

	} while (option);
	return 0;
}
