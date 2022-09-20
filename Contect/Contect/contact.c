#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void initContact(struct Contact* connect)
{
	assert(connect);
	connect->size = 0;
	memset(connect->date, 0, sizeof(struct PeoInfo) * MAX);
}
void addContact(struct Contact* connect)
{
	assert(connect);
	if (connect->size == MAX)
	{
		printf("ͨѶ¼�������޷��������\n");
		return;
	}
	else
	{
		
		printf("������");
		scanf("%s", connect->date[connect->size].name);
		printf("�Ա�");
		scanf("%s", connect->date[connect->size].sex);
		printf("���䣺");
		scanf("%d", &(connect->date[connect->size].age));
		printf("�绰���룺");
		scanf("%s", connect->date[connect->size].tele);
		printf("��ַ��");
		scanf("%s", connect->date[connect->size].adder);
		connect->size++;
		printf("��ӳɹ���\n");
	}
}
int findContact(const struct Contact* connect, char name[])
{
	for (int i = 0; i < connect->size; i++)
	{
		if (0==strcmp(connect->date[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void deleteContact(struct Contact* connect)
{
	char name[MAX_NAME];
	printf("������Ҫɾ����Ϣ�˵�������");
	scanf("%s", name);
	int j = findContact(connect, name);
	if (j >= 0)
	{
		for (int i = j; i < connect->size - 1; i++)
		{
			connect->date[j] = connect->date[j + 1];
		}
		connect->size -= 1;
		printf("ɾ���ɹ���\n");
	}
	else
	{
		printf("ͨѶ¼�в�����Ҫɾ������");
	}
}
void searchContact(const struct Contact* connect)
{
	char name[MAX_NAME];
	printf("������Ҫ������Ϣ�˵�������");
	scanf("%s", name);
	int i = findContact(connect, name);
	if (i!=-1)
	{
	printf("%-10s\t%-6s\t%-6s\t%-12s\t%-15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-10s\t%-6s\t%-6d\t%-12s\t%-15s\n", connect->date[i].name,
			connect->date[i].sex,
			connect->date[i].age,
			connect->date[i].tele,
			connect->date[i].adder);
	}
	else
	{
		printf("ͨѶ¼�в����������ҵ���\n");
	}
	

}
void modifyContact(struct Contact* connect)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸���Ϣ�˵�������");
	scanf("%s", name);
	int i = findContact(connect, name);
	if (i!=-1)
	{
		printf("������");
3;		scanf("%s",connect->date[i].name);
		printf("�Ա�");
		scanf("%s", connect->date[i].sex);
		printf("���䣺");
		scanf("%d", &(connect->date[i].age));
		printf("�绰���룺");
		scanf("%s", connect->date[i].tele);
		printf("��ַ��");
		scanf("%s", connect->date[i].adder);
		printf("�޸ĳɹ���\n");

	}
	else
	{
		printf("ͨѶ¼�в�����Ҫ�޸���Ϣ����\n");
	}
}
void listContact(const struct Contact* connect)
{
	printf("%-10s\t%-6s\t%-6s\t%-12s\t%-15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (int i = 0; i < connect->size; i++)
	{
		printf("%-10s\t%-6s\t%-6d\t%-12s\t%-15s\n", connect->date[i].name,
			connect->date[i].sex,
			connect->date[i].age,
			connect->date[i].tele,
			connect->date[i].adder);
	}
}
//int CmpByAge(const void* e1, const void* e2)
//{
//	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
//}
//
////��������������
//void sortContact(struct Contact* connect)
//{
//	qsort(connect->date, connect->size, sizeof(struct PeoInfo), CmpByAge);
//	printf("����������ɹ���\n");
//	listContect(connect);
//}
int CmpByName(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->name - ((struct PeoInfo*)e2)->name;
}

//��������������
void sortContact(struct Contact* connect)
{
	qsort(connect->date, connect->size, sizeof(struct PeoInfo), CmpByName);
	printf("����������ɹ���\n");
	listContact(connect);
}
void emptyContact(struct Contact* connect)
{
	assert(connect);
	memset(connect->date, 0, sizeof(struct PeoInfo) * MAX);
	printf("��ճɹ���\n");

}