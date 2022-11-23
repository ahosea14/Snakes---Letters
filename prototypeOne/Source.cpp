//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include <time.h>
#include "Application.h"

//main function
int main(int argc, char* args[]) {
	Application game;
	srand(time(0));
	if (!game.init()) {
		printf("Failed to initialize. SDL_Error: %s\n", SDL_GetError());
	}
	else {
		game.startGame();
	}
	game.close();
	return 0;
}
