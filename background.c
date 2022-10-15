#include <stdio.h>

#include "background.h"


char* back[ylength][xlength];


void SetBackground() {
	for (int i = 0; i < ylength; i++) {
		for (int j = 0; j < xlength; j++) {
			if (i >= ylength - 2) {
				if (j != 2 && j != 5 && j != 8 && j != 11) {
					back[i][j] = tile;
				}
				else {
					back[i][j] = " ";
				}
			}
			else {
				back[i][j] = blank;
			}
		}
	}
}

void RenderBackground() {
	system("cls");
	for (int i = 0; i < ylength; i++) {
		backgotoxy(10,i);
		for (int j = 0; j < xlength; j++) {
			printf("%s", back[i][j]);
		}
	}
}