#include"game.h"
void menu()
{
	printf("-------------------------------------\n");
	printf("----------     1.下棋     -----------\n");
	printf("----------     0.退出     -----------\n");
	printf("-------------------------------------\n");
}
void init(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row;i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void print(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) 
		{
		 printf(" %c ", board[i][j]);
		 if (j < col - 1)
		 {
			 printf("|");
		 }
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
			 printf("---");
			 if (j < col - 1)
			 {
				 printf("|");
			 }
			}
			printf("\n");
		}
		
	}
}
void player_move(char board[ROW][COL], int row, int col)
{
	int m = 0 , n = 0;
	printf("请输入下的棋的坐标：");
	scanf("%d%d", &m, &n);
	if (m - 1 < row && n - 1 < col)
	{
		if (board[m-1][n-1] == ' ')
		{
			board[m-1][n-1] = '*';
		}
		else
		{
			printf("该位置已经被占用\n");
		}
	}
	else
	{
		printf("输入的坐标非法！\n");
	}
}
void computer_move(char board[ROW][COL], int row, int col)
{
	srand((unsigned)time(NULL));
	int m = 0, n = 0;
	while (1)
	{
		m = rand() % ROW;
		n = rand() % COL;
		if (m< row && n < col)
		{
			if (board[m][n] == ' ')
			{
				board[m ][n ] = '#';
				break;
			}
		}
	}
}
char is_win(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		int flag = 1;
	 for (int j = 0; j< col; j++)
		{
			
			if (board[i][0] != board[i][j])
			{
				flag = 0;
				break;
			}
			if (board[i][0] == ' ')
			{
				flag = 0;
				break;
			}

		}
	 
	 if (flag == 1)
	 {
		 return board[i][0];
	 }
	}
	for (int j = 0; j < col; j++)
	{
		int flag = 1;
		for (int i = 0; i < row; i++)
		{

			if (board[0][j] != board[i][j])
			{
				flag = 0;
				break;
			}
			if (board[0][j] == ' ')
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			
			return board[0][j];
		}
	}
	int flag = 1;
	for (int i = 1,j=1; i < row&& j < col; i++,j++)
	{
		
		if (board[i][j] != board[i - 1][j - 1])
		{
		flag = 0;
		break;
		}
		if (board[0][0]==' ')
		{
		flag = 0;
		break;
		}
	}
	if (flag == 1)
	{
		return board[0][0];
	}
	int tag = 1;
	for (int i = 1, j = col-2; i < row && j>=0; i++, j--)
	{

		if (board[i][j] != board[i - 1][j +1])
		{
			tag = 0;
			break;
		}
		if (board[0][col-1] == ' ')
		{
			tag = 0;
			break;
		}
	}
	if (tag== 1)
	{
		return board[0][col-1];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'C';
		}
	}
	return 'Q';
}