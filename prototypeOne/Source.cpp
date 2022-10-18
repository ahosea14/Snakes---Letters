//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <filesystem>
#include <string>
#include <vector>
#include <time.h>
#include "Snake.h"
#include "DisplayRender.h"
#include "Application.h"

//Screen dimensions 
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//input controls
enum KeyPress {
	KEY_PRESS_DEFAULT,
	KEY_PRESS_UP,
	KEY_PRESS_DOWN,
	KEY_PRESS_LEFT,
	KEY_PRESS_RIGHT,
	KEY_PRESS_TOTAL
};

//contain starting position, can be used to restart position
enum PlayerStartPOS {
		X = SCREEN_WIDTH / 2,
		Y = SCREEN_HEIGHT / 2
};

enum PlayerCurrentPOS {
	currentX,currentY
};

//contains the players normal sizing
enum PlayerSize {
	W = 30,
	H = 30
};

enum EnemySize {
	eW = 30,
	eH = 30
};

//Number of squares
const int NUM_OF_SQUARES = 5;

//the 2D vector stores the location of each enemy
int enemyLoc[NUM_OF_SQUARES + 1][1]; //only allocating a small amount of space??
SDL_Rect enemies[NUM_OF_SQUARES + 1];

//player speed const
const int PLAYER_SPEED = 10;
const int SPACING = 30;


//Initializing game setup
bool init();
void close();

//Declares the window and the screen that the items will be drawn to
SDL_Window* window = NULL;
SDL_Surface* screen = NULL;
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
			screen = SDL_GetWindowSurface(window);
			if (screen == NULL) {
				printf("SDL Window could not be created. SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
		}
	}
	return success;
}

//function to close window
void close() {
	SDL_FreeSurface(screen);
	screen = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}

//creates player and sets initial location / size values
SDL_Rect* createPlayer(SDL_Surface* screen, SDL_Rect* player) {
	player = new SDL_Rect{X, Y, W, H};
	bool success = true;

	if (screen == NULL) {
		printf("screen not displaying on create player method");
		success = false;
	}
	else {
		if (player == NULL) {
			printf("player is null");
		}
		else {
			SDL_FillRect(screen, player, 0xFF0000FF);
		}
	}
	return player;
}

//player is sent back to starting position without reinitializing rect
bool restartPlayer() {
	bool success = true;
	player->x = X;
	player->y = Y;
	if (player->x != X || player->y != Y) {
		success = false;
		printf("player failed to restart");
	}
	else {
		printf("player is reset");
		SDL_FillRect(screen, player, 0xFF0000FF);
	}
	return success;
}


//creates the enemy rectangle and stores the location of each rectangle in a nested array
void createEnemy(SDL_Surface* screen) {
	for (int i = 0; i <= NUM_OF_SQUARES; i++) {
		SDL_Rect enemy;
		enemy.x = rand() % (640 - eW);
		enemy.y = rand() % (480 - eH);
		enemy.w = eW;
		enemy.h = eH;
		if (i != 0) {
			for (int r = 0; r <= i; r++) {
				if (r != i) {
					if ((enemy.x >= X-SPACING && enemy.x <= X+W+SPACING) && (enemy.y >= Y-SPACING && enemy.y <= Y+H+SPACING)) {
						srand(time(NULL));
						i--; 
						continue;// create a while loop to test for this so it keeps creating new coordinates until the condition is met
					}
					else {
						if ((enemy.x >= enemies[r].x - SPACING && enemy.x <= enemies[r].x + eW + SPACING) && (enemy.y >= enemies[r].y - SPACING && enemy.y <= enemies[r].y + eH + SPACING)) {
							srand(time(NULL));
							i--;
						}
						else {
							SDL_FillRect(screen, &enemy, 0xFF0000FF);
							enemies[i] = enemy;
						}
					}
				} else;
			}
		}
		else {
			SDL_FillRect(screen, &enemy, 0xFF0000FF);
			enemies[i] = enemy;
		}
	}
}

//main function
int main(int argc, char* args[]) {
	srand(time(0));
	if (!init()) {
		printf("Failed to initialize. SDL_Error: %s\n", SDL_GetError());
	}
	else {
		player = createPlayer(screen, player);
		createEnemy(screen);
		bool quit = false;
		SDL_Event e;
		while (!quit) {
			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) { quit = true; }
				else if (e.type == SDL_KEYDOWN) {
					switch (e.key.keysym.sym) {
					//keyboard input structure
					case SDLK_UP:
						if (player->y == 0) {
							SDL_FillRect(screen, player, NULL);
							restartPlayer();
						}
						else {
							SDL_FillRect(screen, player, NULL);
							player->y = player->y - PLAYER_SPEED;
							SDL_FillRect(screen, player, 0xFF0000FF);
						}
						break;
					case SDLK_DOWN:
						if (player->y + player->h == SCREEN_HEIGHT) {
							SDL_FillRect(screen, player, NULL);
							restartPlayer();
						}
						else {
							SDL_FillRect(screen, player, NULL);
							player->y = player->y + PLAYER_SPEED;
							SDL_FillRect(screen, player, 0xFF0000FF);
						}
						break;
					case SDLK_LEFT:
						if (player->x == 0) {
							SDL_FillRect(screen, player, NULL);
							restartPlayer();
						}
						else {
							SDL_FillRect(screen, player, NULL);
							player->x = player->x - PLAYER_SPEED;
							SDL_FillRect(screen, player, 0xFF0000FF);
						}
						break;
					case SDLK_RIGHT:
						if (player->x + player->w == SCREEN_WIDTH) {
							SDL_FillRect(screen, player, NULL);
							restartPlayer();
						}
						else {
							SDL_FillRect(screen, player, NULL);
							player->x = player->x + PLAYER_SPEED;
							SDL_FillRect(screen, player, 0xFF0000FF);
						}
						break;
					default:
						printf("player ready to move.");
						break;
					}
				}
				SDL_UpdateWindowSurface(window);
			}
		}
		
	}
	close();
	return 0;
}
