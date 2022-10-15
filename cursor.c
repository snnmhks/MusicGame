#include <stdio.h>
#include <Windows.h>

#include "cursor.h"

void backgotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void gotoxy(Vector2 vec) // 좌표 위치를 받아서 커서를 좌표 위치로 옮기는 함수
{
	COORD pos = { vec.x * 5 + 10, vec.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void gotoxplusy(Vector2 vec) // 좌표 위치를 받아서 커서를 좌표 위치로 옮기는 함수
{
	COORD pos = { vec.x * 5 + 10, vec.y + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void HideCursor() // 커서 숨기기, 정형화 되어 있으니 그냥 사용하면 됨
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}