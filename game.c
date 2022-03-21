#include "game.h"

// ��ʼ������
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

// ��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	// ��ӡ�к��к����Ż�����
	// ��ӡ�к�
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		// ��ӡ�к�
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

// ������
void SetMine(char mine[ROWS][COLS], int row, int col, int set_mine_count)
{
	// ����10����
	//int set_mine_count = 10;
	while (set_mine_count)
	{
		// ����������±�
		int x = rand() % row +1;
		int y = rand() % col +1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			set_mine_count--;
		}
	}
}

// ͳ��ĳ�����������׵ĸ���
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
// ������д��  // ����static��ʹ�ú���ֻ��game.c�пɼ������������ͻ��
// static ���ã�
// 1. ���ξֲ�����
// 2. ����ȫ�ֱ���
// 3. ���κ���
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
//			mine[x + 1][y + 1] - 8 * '0';    // �ο�ASCII�����0�� -- 48 �� ��1�� -- 49 �� ��2�� -- 50
//}

// �Ų���
// My Eition
//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	int count = 0;  //���ڴ��ÿ���������ܵ��׵�����
//	for (i = 1; i <= row; i++)
//	{
//		for (j = 1; j <= col; j++)
//		{
//			//if (mine[i][j] == '1')
//			//{
//			//	// �����ˣ���Ϸ����
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
//			// �Ų��׽�������i,j�������׵����������count��
//			// int ת char
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
	// 1. �����Ų������
	// 2. ������괦�ǲ�����
	  // (1) �� -> ��Ϸ����
	  // (2) ���� -> ͳ��������Χ�м����� -> �洢�� show �����У���Ϸ����

	int x = 0;
	int y = 0;
	int play_count_max = ROW * COL - set_mine_count;
	// �ж�����ĺϷ���
	while (play_count_max)
	{
		printf("������Ҫ�Ų�����꣺\n");
		scanf_s("%d%d", &x, &y);   // ���귶Χ��1-(ROW-2)
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("����ը�ˣ���Ϸ������\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				// �����׵�����£�ͳ����Χ�׵ĸ���
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';   //�ο�ASCII�����0�� -- 48 �� ��1�� -- 49 �� ��2�� -- 50
				DisplayBoard(show, row, col);
			}
			play_count_max--;
		}
		else
		{
			printf("���겻�Ϸ����������룺\n");
		}
	}
	printf("��ϲ����ɨ�׳ɹ���");
}




