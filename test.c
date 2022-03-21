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
	char mine[ROWS][COLS] = { 0 }; // ��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 }; // ����Ų�����׵���Ϣ

	// ��ʼ������
	InitBoard(mine, ROWS, COLS, '0');  // ����flag: 0 -> mine ; 1-> show
	InitBoard(show, ROWS, COLS, '*');

	// ��ӡһ������
	//printf("���̳�ʼ�������\n");
	//DisplayBoard(mine, ROW, COL);  // ��Ϸ�����в��ܴ�ӡ����
	//printf("\n");
	DisplayBoard(show, ROW, COL);

	// ������
	int set_mine_count = 4;   // �����׵�����
	SetMine(mine, ROW, COL, set_mine_count);
	// ��鲼�����
	printf("\n�����׵����: \n");
	DisplayBoard(mine, ROW, COL);

	// �Ų���
	FindMine(mine, show, ROW, COL, set_mine_count);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));  // ʱ�������ȡ���Ե�ʱ��ʱ�䣬���������
	do
	{
		menu();
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼɨ����Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}

// ���Ż���
// 1. ��������ף���չ��һƬ -�� �ݹ�
// 2. �����