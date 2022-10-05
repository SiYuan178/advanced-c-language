#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	init(mine, ROWS, COLS, '0');
	init(show, ROWS, COLS, '*');
	set_bomb(mine, ROW, COL);
	//print(mine, ROW, COL);
	print(show, ROW, COL);
	minesweeper(mine, show, ROW, COL);
}
int main()
{
	int option=0;
	do
	{
		menu();
		printf("请输入：");
		scanf("%d",&option);
		switch (option)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出成功！\n");
			break;
		default:
			printf("你的输入有误，请重新输入：");
		}

	} while (option);
	return 0;
}