#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("--------------------------------------------------------------------\n");
	printf("-----------1.add                  2.delete--------------------------\n");
	printf("-----------3.search               4.modify--------------------------\n");
	printf("-----------5.sort                 6.list----------------------------\n");
	printf("-----------7.empty                0.exit----------------------------\n");
	printf("--------------------------------------------------------------------\n");
}
int main()
{
	int input=0;
	struct Contact connect;
	initContact(&connect);
	do
	{
		menu();
		printf("��������Ҫ���еĲ�����");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			addContact(&connect);
			break;
		case 2:
			deleteContact(&connect);
			break;
		case 3:
			searchContact(&connect);
			break;
		case 4:
			modifyContact(&connect);
			break;
		case 5:
			sortContact(&connect);
			break;
		case 6:
			listContact(&connect);
			break;
		case 7:
			emptyContact(&connect);
			break;
		case 0:
			printf("�˳��ɹ���\n");
			break;
		default:
			printf("������������");
			break;
		}
		
	} while (input);

	return 0;
}