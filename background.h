#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#define ylength 10 // ���� ���õ� ����
#define xlength 14
#define tile "��"
#define block "��"
#define blank "  "

typedef struct Vector2 {
	int x;
	int y;
}Vector2;

void SetBackground();

void RenderBackground();

#endif