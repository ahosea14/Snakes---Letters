//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <filesystem>
#include <string>
#include <vector>
#include <time.h>
#include "Snake.h"
#include "Application.h"
#include "Enemy.h"

//Screen dimensions 
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Initializing game setup
bool init();
void close();

//Declares the window and the screen that the items will be drawn to
SDL_Window* window = NULL;
SDL_Renderer* cRenderer = NULL;
SDL_Texture* cTexture = NULL;
SDL_Surface* testSurface = NULL;
SDL_Surface*playerScreen = NULL;
SDL_Surface* enemyScreen = NULL;
SDL_Rect* player;

//method definition for init()
bool init() {
	//flag to track the accuracy of the program
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		window = SDL_CreateWindow("Prototype One", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("SDL Window could not be created. SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			cRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawColor(cRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			int imgFlags = IMG_INIT_PNG;
			playerScreen = SDL_GetWindowSurface(window);
			enemyScreen = SDL_GetWindowSurface(window);
			if (playerScreen == NULL || enemyScreen == NULL) {
				printf("SDL Window could not be created. SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
		}
	}
	return success;
}

//function to close window
void close() {
	SDL_FreeSurface(playerScreen);
	playerScreen = NULL;

	SDL_FreeSurface(enemyScreen);
	enemyScreen = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}

//main function
int main(int argc, char* args[]) {
	srand(time(0));
	if (!init()) {
		printf("Failed to initialize. SDL_Error: %s\n", SDL_GetError());
	}
	else {
		Snake player;
		SDL_Rect* playerRender = player.renderPlayer(playerScreen);
		Enemy enemy;
		enemy.renderEnemy(enemyScreen);
		SDL_UpdateWindowSurface(window);
		bool quit = false;
		SDL_Event playerInput;
		while (!quit) {
			while(SDL_PollEvent(&playerInput) != 0){
				if (playerInput.type == SDL_QUIT) {
					quit = true;
				}
				else {
					player.handleEvent(playerInput);
					player.move(playerScreen, playerRender);
					SDL_UpdateWindowSurface(window);
				}
			}
		}
		
	}
	close();
	return 0;
}
