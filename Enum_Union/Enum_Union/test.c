#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//enum Color
//{
//	BLUE=6,//注意这里用,进行分隔，而不是;
//    RED,
//	PINK,
//	BLACK,
//	WHITE
//
//};
//int main()
//{
//	enum Color color = BLUE;
//	printf("%d\n", color);
//	printf("%d\n", RED);
//	printf("%d\n", PINK);
//	/*printf("%d\n", sizeof(color));
//	printf("%d\n", sizeof(enum Color));*/
//	return 0;
//}
//enum Option
//{
//	exit,
//	add,
//	delete,
//	search,
//	modify,
//	sort,
//	list,
//	empty
//};
//void menu()
//{
//	printf("--------------------------------------------------------------------\n");
//	printf("-----------1.add                  2.delete--------------------------\n");
//	printf("-----------3.search               4.modify--------------------------\n");
//	printf("-----------5.sort                 6.list----------------------------\n");
//	printf("-----------7.empty                0.exit----------------------------\n");
//	printf("--------------------------------------------------------------------\n");
//}
//int main()
//{
//	enum Option option;
//	do
//	{
//		menu();
//		scanf("%d", &option);
//		switch (option)
//		{
//		case exit:
//			printf("退出成功！\n");
//			break;
//		case add:
//			printf("添加成功！\n");
//			break;
//			//后面代码的修改类似，这里注重enum的使用场景，对通讯录功能实现在上个博客有详细说明
//		}
//	} while (option);
//	return 0;
//}
//联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union Un un;//联合类型的定义
//	//printf("%d", sizeof(un));//计算联合类型变量的大小
//	/*printf("%d\n", &(un.i));
//	printf("%d\n", &(un.c));*/
//	un.i = 0x112233;
//	un.c = 0x66;
//	printf("%x\n", un.i);
//	return 0;
//}
//union Un1
//{
//	char c[5];//5 1VS8 1
//	int i;// 4VS8 4
//};
//union Un2
//{
//	short c[7];//14 2VS8 2
//	int i; //4VS8 4
//};
//int main()
//{
//printf("%d\n", sizeof(union Un1));
//printf("%d\n", sizeof(union Un2));
//}
union Un
{
	int i;
	char c;
};
int main()
{
	//利用联合判断大小端存储
	union Un u1;
	u1.i = 1;
	if (u1.c == 1)
	{
		printf("小端存储!");
	}
	else
	{
		printf("大端存储！");
	}
}
