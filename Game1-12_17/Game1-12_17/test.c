#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void menu()
{
	printf("*******************\n");
	printf("****  1.play   ****\n");
	printf("***** 0.exit   ****\n");
	printf("*******************\n");
} 
void  game()
{
	char ret = 0;
	char board[ROW][COL];
	//初始化一下棋盘为全空格
	init_board(board, ROW, COL);
	print_board(board, ROW, COL);
	while (1)
	{
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		//判断输赢
		ret = is_win(board, ROW, COL);
		if (ret != 'C')//出现胜负和平局
		{
			break;
		}
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		//判断输赢
		ret = is_win(board, ROW, COL);
		if (ret != 'C')//出现胜负和平局
		{
			break;
		}
	
	}
	if (ret == '#')
		printf("comuter win\n");
	else if (ret == '*')
		printf("player win\n");
	else if (ret == 'Q')
		printf("平局\n");
}
//判断输赢
//玩家赢：*
//电脑赢：#
//平局：Q
//游戏继续：C
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("game start\n");
			game();
			break;
		case 0:
			printf("game end\n");
			break;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}