#include <stdio.h>
#include <Windows.h>

#include "tile.h"

static int blockspeed_0 = 0;
int blockspeed_1 = 3;
int blockmin = 0;
static int blockmax = 2;
static int blockterm_0 = 0;
static int blockterm_1 = 20;
static time_t before;
static int number[5] = { 0,1,2,3,4 };
static int num[5] = { 0,1,2,3,4 };

/////////////////////////
int order;
/////////////////////////

Vector2 blocks[30] = {0,0};

void CreateBlock() {
	// �ð� ������ seed���� ������ �Ŀ� �����Ѵ�.
	time_t current = time(NULL);		// 1970����� ���ݱ��� �帥 �ð� �� (��)
	if (current != before)				// ���� �ð��� ���� �ð��� �ٸ��ٸ� (1�ʰ� �����ٸ�)
	{
		srand(current);					// ���ο� �õ尪 ���� (n��° ����ǥ ���� �غ�)
		before = current;				// ���� �ð��� ���� �ð��� ����.
	}

	blocks[0].x = (rand() % 4);
}

void RenderBlock() {
	if (blockterm_0 == blockterm_1) { 
		int blocknum = rand() % 3 + 1;
		blockmax += blocknum; 

		for (int i = 0; i < 4; i++) {
			int choice = number[rand() % (4-i)];
			int temp = num[choice];
			num[choice] = num[4 - i];
			num[4 - i] = temp;
		}

		for (int i = 0; i < blocknum; i++) {
			blocks[blockmax + i].x = num[i];
		}
		blockterm_0 = 0; 
	}
	
	for (int i = blockmin; i < blockmax; i++) {
		int j = i;
		if (j >= 30) j -= 30;
		gotoxy(blocks[j]);
		printf("%s%s", block, block);
		gotoxplusy(blocks[j]);
		printf("%s%s", block, block);
	}

	if (blockmin >= 30) {
		blockmax -= 30;
		blockmin -= 30;
	}

	blockterm_0 += 1;
}

void MoveBlock() {
	if (blockspeed_0 < blockspeed_1) {
		blockspeed_0 += 1;
		return;
	}

	for (int i = blockmin; i < blockmax; i++) {
		int j = i;
		if (j >= 30) j -= 30;
		blocks[j].y += 1; // y�������� �̻����� �����δ�.

		if (blocks[j].y >= ylength - 1) { // �̻����� ���� �Ѿ�� �ʱ� ��ġ�� �ǵ�����.
			blocks[j].y = 0;
			blocks[j].x = -1;
			blockmin += 1;
			order += 1;
		}
	}
	blockspeed_0 = 0;
}