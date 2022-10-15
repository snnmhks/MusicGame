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
	// 시간 값으로 seed값을 결정한 후에 대입한다.
	time_t current = time(NULL);		// 1970년부터 지금까지 흐른 시간 값 (초)
	if (current != before)				// 이전 시간과 현재 시간이 다르다면 (1초가 지났다면)
	{
		srand(current);					// 새로운 시드값 대입 (n번째 난수표 새로 준비)
		before = current;				// 이전 시간에 현재 시간을 대입.
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
		blocks[j].y += 1; // y방향으로 미사일을 움직인다.

		if (blocks[j].y >= ylength - 1) { // 미사일이 벽을 넘어가면 초기 위치로 되돌린다.
			blocks[j].y = 0;
			blocks[j].x = -1;
			blockmin += 1;
			order += 1;
		}
	}
	blockspeed_0 = 0;
}