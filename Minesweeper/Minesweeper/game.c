#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*********************************************\n");
	printf("*******          1.开始扫雷       ***********\n");
	printf("*******          0.退出游戏       ***********\n");
	printf("*********************************************\n");
}
void init(char arr[ROW][COL], int row, int col, char ch)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = ch;
		}
	}
}
void print(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i <= COL; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i =1; i <= row; i++)
	{
		printf("%d ", i );
		for (int j =1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
void set_bomb(char arr[ROW][COL], int row, int col)
{
	srand((unsigned)time(NULL));
	int count = BOMB;
	while (count)
	{
		int x = rand() % row+1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}

	}
}
int cout_bomb(char arr[ROW][COL], int x, int y)
{
	return (arr[x - 1][y] +
		arr[x - 1][y - 1] +
		arr[x][y - 1] +
		arr[x + 1][y - 1] +
		arr[x + 1][y] +
		arr[x + 1][y + 1] +
		arr[x][y + 1] +
		arr[x - 1][y + 1] - 8 * '0');
}
void minesweeper(char mine[ROW][COL], char show[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	int win = 0;
	while (win < ROW * COL - BOMB)
	{
	printf("请输入要排查雷的坐标:");
		scanf("%d%d", &x, &y);
		if (x< row &&x>=1&& y < col&&y>=1)
		{
			if (show[x][y] == '*')
					{
						if (mine[x][y] == '0')
						{
							show[x][y] = cout_bomb(mine, x, y)+'0';
							win++;
							print(show, ROW, COL);
						}
						else
						{
							printf("您已炸死，游戏结束\n");
							print(mine, row, col);
							break;
						}
					}
					else
					{
						printf("该位置已经排查过\n");
					}
		}
		else
		{
			printf("输入坐标不合法\n");
		}
		
	}
	if (win == ROW * COL - BOMB)
	{
		printf("排雷成功，游戏结束！\n");
	}
	

}