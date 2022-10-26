#pragma once
#include <SDL.h>
#include <stdio.h>

//Global Variables
//size of the screen
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class Application
{
public:
	//Declares the window and the screen that the items will be drawn to
	SDL_Window* window;
	SDL_Renderer* cRenderer;
	SDL_Texture* cTexture;
	SDL_Surface* testSurface;
	SDL_Surface* playerScreen;
	SDL_Surface* enemyScreen;

	//Method definition for init()
	bool init();

	//Function to close window
	void close();

	bool startGame(Application game);
};

