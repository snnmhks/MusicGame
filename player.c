#include <stdio.h>
#include <Windows.h>

#include "player.h"

Vector2 blocks[30];
Vector2 score = {3,12};

int PlayerKey[6] = { 0, };
int order = 0;

/////////////////////////
int blockspeed_1;
int blockmin;
/////////////////////////

void SetPlayer() {
	printf("Ű ������ �մϴ�.\n");
	printf("5���� Ű�� �������ּ���.\n");
	printf("1��° Ű : ");
	PlayerKey[0] = _getch();
	printf("\n2��° Ű : ");
	PlayerKey[1] = _getch();
	printf("\n3��° Ű : ");
	PlayerKey[2] = _getch();
	printf("\n4��° Ű : ");
	PlayerKey[3] = _getch();
	printf("\n5��° Ű : ");
	PlayerKey[4] = _getch();
	for (int i = 0; i < 5; i++) { // ��ҹ��� ����
		if (PlayerKey[i] <= 122 && PlayerKey[i] >= 97) {
			PlayerKey[i] -= 32;
		}
	}
	printf("\n�����Ͻ� Ű�� ���ʺ��� ���ʴ�� %c %c %c %c %c �Դϴ�.", PlayerKey[0], PlayerKey[1], PlayerKey[2], PlayerKey[3], PlayerKey[4]);
	printf("\n�����Ϸ��� �ƹ�Ű�� ��������");
	PlayerKey[5] = _getch();
}

void pop(Vector2 blocks) {
	backgotoxy(blocks.x *5 + 9, blocks.y-1);
	printf("%s", block);
	backgotoxy(blocks.x * 5 + 14, blocks.y - 1);
	printf("%s", block);
	backgotoxy(blocks.x * 5 + 9, blocks.y +2);
	printf("%s", block);
	backgotoxy(blocks.x * 5 + 14, blocks.y + 2);
	printf("%s", block);
}

void InputKey() {

	for (int i = 0; i < 5; i++) {
		if (order >= 30) order -= 30;
		if (GetAsyncKeyState(PlayerKey[blocks[order].x]) & 0x0001) {
			switch (blocks[order].y) {
			case ylength - 2:
				gotoxy(score);
				printf("Greate!");
				pop(blocks[order]);
				blocks[order].y = 0;
				blocks[order].x = -1;
				order += 1;
				blockmin += 1;
				break;
			case ylength - 3:
				gotoxy(score);
				printf("Good!");
				pop(blocks[order]);
				blocks[order].y = 0;
				blocks[order].x = -1;
				order += 1;
				blockmin += 1;
				break;
			case ylength - 4:
				gotoxy(score);
				printf("Bad...");
				blocks[order].y = 0;
				blocks[order].x = -1;
				order += 1;
				blockmin += 1;
				break;
			}

		}
	}

	if (GetAsyncKeyState(VK_UP) & 0x0001) {
		if (blockspeed_1 != 0) {
			blockspeed_1 -= 1;
		}
		return;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
		if (blockspeed_1 != 10) {
			blockspeed_1 += 1;
		}
		return;
	}
	else return;
}