#define _CRT_SECURE_NO_WARNINGS 1
#include"contect.h"
void initContect(struct Contect* connect)
{
	assert(connect);
	connect->size = 0;
	memset(connect->date, 0, sizeof(struct PeoInfo) * MAX);
}
void addContect(struct Contect* connect)
{
	assert(connect);
	if (connect->size == MAX)
	{
		printf("通讯录已满，无法继续添加\n");
		return;
	}
	else
	{
		
		printf("姓名：");
		scanf("%s", connect->date[connect->size].name);
		printf("性别：");
		scanf("%s", connect->date[connect->size].sex);
		printf("年龄：");
		scanf("%d", &(connect->date[connect->size].age));
		printf("电话号码：");
		scanf("%s", connect->date[connect->size].tele);
		printf("地址：");
		scanf("%s", connect->date[connect->size].adder);
		connect->size++;
		printf("添加成功！\n");
	}
}
int findContect(const struct Contect* connect, char name[])
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
void deleteContect(struct Contect* connect)
{
	char name[MAX_NAME];
	printf("请输入要删除信息人的姓名：");
	scanf("%s", name);
	int j = findContect(connect, name);
	if (j >= 0)
	{
		for (int i = j; i < connect->size - 1; i++)
		{
			connect->date[j] = connect->date[j + 1];
		}
		connect->size -= 1;
		printf("删除成功！\n");
	}
	else
	{
		printf("通讯录中不存在要删除的人");
	}
}
void searchContect(const struct Contect* connect)
{
	char name[MAX_NAME];
	printf("请输入要查找信息人的姓名：");
	scanf("%s", name);
	int i = findContect(connect, name);
	if (i!=-1)
	{
	printf("%-10s\t%-6s\t%-6s\t%-12s\t%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-10s\t%-6s\t%-6d\t%-12s\t%-15s\n", connect->date[i].name,
			connect->date[i].sex,
			connect->date[i].age,
			connect->date[i].tele,
			connect->date[i].adder);
	}
	else
	{
		printf("通讯录中不存在所查找的人\n");
	}
	

}
void modifyContect(struct Contect* connect)
{
	char name[MAX_NAME];
	printf("请输入要修改信息人的姓名：");
	scanf("%s", name);
	int i = findContect(connect, name);
	if (i!=-1)
	{
		printf("姓名：");
3;		scanf("%s",connect->date[i].name);
		printf("性别：");
		scanf("%s", connect->date[i].sex);
		printf("年龄：");
		scanf("%d", &(connect->date[i].age));
		printf("电话号码：");
		scanf("%s", connect->date[i].tele);
		printf("地址：");
		scanf("%s", connect->date[i].adder);
		printf("修改成功！\n");

	}
	else
	{
		printf("通讯录中不存在要修改信息的人\n");
	}
}
void listContect(const struct Contect* connect)
{
	printf("%-10s\t%-6s\t%-6s\t%-12s\t%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < connect->size; i++)
	{
		printf("%-10s\t%-6s\t%-6d\t%-12s\t%-15s\n", connect->date[i].name,
			connect->date[i].sex,
			connect->date[i].age,
			connect->date[i].tele,
			connect->date[i].adder);
	}
}
int CmpByAge(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}

//按照年龄来排序
void sortContect(struct Contect* connect)
{
	qsort(connect->date, connect->size, sizeof(struct PeoInfo), CmpByAge);
	printf("对年龄排序成功！\n");
	listContect(connect);
}