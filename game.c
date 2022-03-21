#include "game.h"

// 初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = ret;
		}
	}
}

// 打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	// 打印行号列号以优化界面
	// 打印列号
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		// 打印行号
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

// 布置雷
void SetMine(char mine[ROWS][COLS], int row, int col, int set_mine_count)
{
	// 布置10个雷
	//int set_mine_count = 10;
	while (set_mine_count)
	{
		// 生成随机的下标
		int x = rand() % row +1;
		int y = rand() % col +1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			set_mine_count--;
		}
	}
}

// 统计某个坐标四周雷的个数
//int GetMineCount(char mine[ROWS][COLS], int x, int y)
//{
//	int count = 0;
//	for (int k = -1; k <= 1; k++)
//	{
//		if (mine[x - 1][y + k] == '1')
//		{
//			count++;
//		}
//		if (mine[x + 1][y + k] == '1')
//		{
//			count++;
//		}
//		if (mine[x][y + k] == '1')
//		{
//			count++;
//		}
//	}
//	return count;
//}
// 更简洁的写法  // 加上static，使该函数只在game.c中可见，不会产生冲突。
// static 作用：
// 1. 修饰局部变量
// 2. 修饰全局变量
// 3. 修饰函数
static int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (mine[x + i][y + j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}
// or
//static int GetMineCount(char mine[ROWS][COLS], int x, int y)
//{
//	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
//			 mine[x][y - 1] + mine[x][y + 1] + 
//			mine[x + 1][y - 1] + mine[x + 1][y] + 
//			mine[x + 1][y + 1] - 8 * '0';    // 参考ASCII码表：‘0’ -- 48 ； ‘1’ -- 49 ； ‘2’ -- 50
//}

// 排查雷
// My Eition
//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	int count = 0;  //用于存放每个坐标四周的雷的数量
//	for (i = 1; i <= row; i++)
//	{
//		for (j = 1; j <= col; j++)
//		{
//			//if (mine[i][j] == '1')
//			//{
//			//	// 踩雷了，游戏结束
//			//}
//			//else
//			//{
//				for (int k = -1; k <= 1; k++)
//				{
//					if (mine[i - 1][j + k] == '1')
//					{
//						count++;
//					}
//					if (mine[i + 1][j + k] == '1')
//					{
//						count++;
//					}
//					if (mine[i][j + k] == '1')
//					{
//						count++;
//					}
//				}
//			//}
//			// 排查雷结束，（i,j）四周雷的数量存放在count中
//			// int 转 char
//			//char Count = (char)(count + 48);
//			char Count;
//			_itoa(count, Count, 10);
//			show[i][j] = Count;
//		}
//	}
//}

// Better Eidtion
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int set_mine_count)
{
	// 1. 输入排查的坐标
	// 2. 检查坐标处是不是雷
	  // (1) 是 -> 游戏结束
	  // (2) 不是 -> 统计坐标周围有几个雷 -> 存储到 show 数组中，游戏继续

	int x = 0;
	int y = 0;
	int play_count_max = ROW * COL - set_mine_count;
	// 判断坐标的合法性
	while (play_count_max)
	{
		printf("请输入要排查的坐标：\n");
		scanf_s("%d%d", &x, &y);   // 坐标范围：1-(ROW-2)
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("您被炸了！游戏结束。\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				// 不是雷的情况下，统计周围雷的个数
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';   //参考ASCII码表：‘0’ -- 48 ； ‘1’ -- 49 ； ‘2’ -- 50
				DisplayBoard(show, row, col);
			}
			play_count_max--;
		}
		else
		{
			printf("坐标不合法，重新输入：\n");
		}
	}
	printf("恭喜您！扫雷成功！");
}




