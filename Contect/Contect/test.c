#define _CRT_SECURE_NO_WARNINGS 1
#include"contect.h"
void menu()
{
	printf("--------------------------------------------------------------------\n");
	printf("-----------1.add                  2.delete--------------------------\n");
	printf("-----------3.search               4.modify--------------------------\n");
	printf("-----------5.sort                 6.list----------------------------\n");
	printf("-----------0.exit                       ----------------------------\n");
	printf("--------------------------------------------------------------------\n");
}
int main()
{
	int input=0;
	struct Contect connect;
	initContect(&connect);
	do
	{
		menu();
		printf("请输入您要进行的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			addContect(&connect);
			break;
		case 2:
			deleteContect(&connect);
			break;
		case 3:
			searchContect(&connect);
			break;
		case 4:
			modifyContect(&connect);
			break;
		case 5:
			sortContect(&connect);
			break;
		case 6:
			listContect(&connect);
			break;
		case 0:
			break;
		default:
			printf("您的输入有误！");
			break;
		}
		
	} while (input);

	return 0;
}