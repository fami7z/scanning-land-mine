#include <stdio.h>
#include "game.h"

void menu()
{
	printf("*******************\n");
	printf("****  1->play  ****\n");
	printf("****  0->exit  ****\n");
	printf("*******************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 }; // 存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 }; // 存放排查出的雷的信息

	// 初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');  // 设置flag: 0 -> mine ; 1-> show
	InitBoard(show, ROWS, COLS, '*');

	// 打印一下棋盘
	//printf("棋盘初始化情况：\n");
	//DisplayBoard(mine, ROW, COL);  // 游戏过程中不能打印出来
	//printf("\n");
	DisplayBoard(show, ROW, COL);

	// 布置雷
	int set_mine_count = 4;   // 布置雷的数量
	SetMine(mine, ROW, COL, set_mine_count);
	// 检查布置情况
	printf("\n布置雷的情况: \n");
	DisplayBoard(mine, ROW, COL);

	// 排查雷
	FindMine(mine, show, ROW, COL, set_mine_count);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));  // 时间戳，获取电脑当时的时间，产生随机数
	do
	{
		menu();
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始扫雷游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}

// 可优化：
// 1. 如果不是雷，则展开一片 -》 递归
// 2. 标记雷