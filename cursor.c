#include <stdio.h>
#include <Windows.h>

#include "cursor.h"

void backgotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void gotoxy(Vector2 vec) // ��ǥ ��ġ�� �޾Ƽ� Ŀ���� ��ǥ ��ġ�� �ű�� �Լ�
{
	COORD pos = { vec.x * 5 + 10, vec.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void gotoxplusy(Vector2 vec) // ��ǥ ��ġ�� �޾Ƽ� Ŀ���� ��ǥ ��ġ�� �ű�� �Լ�
{
	COORD pos = { vec.x * 5 + 10, vec.y + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void HideCursor() // Ŀ�� �����, ����ȭ �Ǿ� ������ �׳� ����ϸ� ��
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}