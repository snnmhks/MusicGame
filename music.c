#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")
#include "music.h"

void PlayMusic() {
	PlaySound(TEXT("./../LostARK.wav"), NULL, SND_ASYNC);
}