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
		printf("�������壺\n");
		print(board, ROW, COL);
		if ('C' != ret)
		{
			break;
		}
	}
	if (ret == 'Q')
	{
		printf("ƽ�֣�\n");
	}
	else if (ret == '*')
	{
		printf("��Ӯ�ˣ�\n");
	}
	else if(ret == '#')
	{
		printf("����Ӯ��\n");
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
		printf("��ѡ��");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳��ɹ���\n");
			break;
		default:
			printf("���������������������룡\n");
		}
	} while (option);
	return 0;
}