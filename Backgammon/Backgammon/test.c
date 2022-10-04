#include"game.h"
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	init(board, ROW, COL);
	print(board, ROW, COL);
	while (1)
	{
		player_move(board, ROW, COL);
		print(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if ('C' != ret)
		{ 
			break;
		}
		computer_move(board, ROW, COL);
		printf("电脑下棋：\n");
		print(board, ROW, COL);
		if ('C' != ret)
		{
			break;
		}
	}
	if (ret == 'Q')
	{
		printf("平局！\n");
	}
	else if (ret == '*')
	{
		printf("您赢了！\n");
	}
	else if(ret == '#')
	{
		printf("电脑赢！\n");
	}
}
int main()
{
	char board[ROW][COL] = { 0 };
	init(board, ROW, COL);
	int option = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出成功！\n");
			break;
		default:
			printf("您的输入有误，请重新输入！\n");
		}
	} while (option);
	return 0;
}