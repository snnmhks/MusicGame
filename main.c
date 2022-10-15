#include <stdio.h>
#include <Windows.h>

#include "background.h"
#include "cursor.h"
#include "player.h"
#include "music.h"

int main() {
	SetPlayer();
	HideCursor();
	SetBackground();
	CreateBlock();
	PlayMusic();
	while (1) {
		RenderBackground();
		MoveBlock();
		InputKey();
		RenderBlock();
		Sleep(33.3);
	}
}