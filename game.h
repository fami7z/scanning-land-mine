#pragma once
#include <stdio.h>
// �����
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

#define COLS ROW + 2
#define ROWS ROW + 2

//#define set_mine_count 10

// ��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret);

// ��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);

// ������
void SetMine(char mine[ROWS][COLS], int row, int col, int set_mine_count);

// �Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int set_mine_count);

//// ͳ��ĳ�����������׵ĸ���
//int GetMineCount(char mine[ROWS][COLS], int x, int y);
// �˺�������Ҫ��ͷ�ļ�������
