#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#define ylength 10 // 벽에 관련된 값들
#define xlength 14
#define tile "■"
#define block "□"
#define blank "  "

typedef struct Vector2 {
	int x;
	int y;
}Vector2;

void SetBackground();

void RenderBackground();

#endif