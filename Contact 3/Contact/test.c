#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
enum Option
{
	quit,
	add,
	delete,
	search,
	modify,
	sort,
	list,
	empty
};
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
	enum Option option;
	struct Contact connect;
	initContact(&connect);
	do
	{
		menu();
		printf("��������Ҫ���еĲ�����");
		scanf("%d", &option);
		switch (option)
		{
		case add:
			addContact(&connect);
			break;
		case delete:
			deleteContact(&connect);
			break;
		case search:
			searchContact(&connect);
			break;
		case modify:
			modifyContact(&connect);
			break;
		case sort:
			sortContact(&connect);
			break;
		case list:
			listContact(&connect);
			break;
		case empty:
			emptyContact(&connect);
			break;
		case quit:
			saveContact(&connect);
			destoryContact(&connect);
			printf("����ɹ���\n");
			printf("�˳��ɹ���\n");
			break;
		default:
			printf("������������");
			break;
		}

	} while (option);

	return 0;
}