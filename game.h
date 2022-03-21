#pragma once
#include <stdio.h>
// 随机数
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

#define COLS ROW + 2
#define ROWS ROW + 2

//#define set_mine_count 10

// 初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret);

// 打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);

// 布置雷
void SetMine(char mine[ROWS][COLS], int row, int col, int set_mine_count);

// 排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int set_mine_count);

//// 统计某个坐标四周雷的个数
//int GetMineCount(char mine[ROWS][COLS], int x, int y);
// 此函数不需要在头文件里声明
