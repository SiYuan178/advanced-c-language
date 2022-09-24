#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void initContact(struct Contact* connect)
{
	assert(connect);
	connect->size = 0;
	connect->capacity = FAULT_SZ;
	 connect->data= (struct PeoInfo*)malloc(FAULT_SZ * sizeof(struct PeoInfo));
	memset(connect->data, 0, sizeof(struct PeoInfo) * connect->capacity);
}
void destoryContact(struct Contact* connect)
{
	free(connect);
	connect = NULL;
}
int check_is_full( struct Contact* connect)
{
	if (connect->size == connect->capacity)
	{
		struct PeoInfo* p = (struct PeoInfo*)realloc(connect->data, (connect->capacity+EXPAND_SZ) * sizeof(struct PeoInfo));
		if (p != NULL)
		{
			connect->data = p;
			connect->capacity += EXPAND_SZ;
			printf("���ݳɹ���\n");
			p = NULL;
			return 1;
		}
		else
		{
			printf("����ʧ�ܣ��޷��ټ������ӣ�");
			return 0;
		}
		
	}
	else
	{
		return 1;
	}
}
void addContact(struct Contact* connect)
{
	assert(connect);
	int flag = check_is_full(connect);
	if (flag)
	{
			printf("������");
			scanf("%s", connect->data[connect->size].name);
			printf("�Ա�");
			scanf("%s", connect->data[connect->size].sex);
			printf("���䣺");
			scanf("%d", &(connect->data[connect->size].age));
			printf("�绰���룺");
			scanf("%s", connect->data[connect->size].tele);
			printf("��ַ��");
			scanf("%s", connect->data[connect->size].adder);
			connect->size++;
			printf("���ӳɹ���\n");
	}
	else
	{
		return;
	}
	
}
int findContact(const struct Contact* connect, char name[])
{
	for (int i = 0; i < connect->size; i++)
	{
		if (0 == strcmp(connect->data[i].name, name))
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
			connect->data[j] = connect->data[j + 1];
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
	if (i != -1)
	{
		printf("%-10s\t%-6s\t%-6s\t%-12s\t%-15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-10s\t%-6s\t%-6d\t%-12s\t%-15s\n", connect->data[i].name,
			connect->data[i].sex,
			connect->data[i].age,
			connect->data[i].tele,
			connect->data[i].adder);
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
	if (i != -1)
	{
		printf("������");
		3;		scanf("%s", connect->data[i].name);
		printf("�Ա�");
		scanf("%s", connect->data[i].sex);
		printf("���䣺");
		scanf("%d", &(connect->data[i].age));
		printf("�绰���룺");
		scanf("%s", connect->data[i].tele);
		printf("��ַ��");
		scanf("%s", connect->data[i].adder);
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
		printf("%-10s\t%-6s\t%-6d\t%-12s\t%-15s\n", connect->data[i].name,
			connect->data[i].sex,
			connect->data[i].age,
			connect->data[i].tele,
			connect->data[i].adder);
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
	qsort(connect->data, connect->size, sizeof(struct PeoInfo), CmpByName);
	printf("����������ɹ���\n");
	listContact(connect);
}
void emptyContact(struct Contact* connect)
{
	assert(connect);
	memset(connect->data, 0, sizeof(struct PeoInfo) * MAX);
	printf("��ճɹ���\n");

}