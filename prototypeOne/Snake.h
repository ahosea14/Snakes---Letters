#include <SDL.h>
#include <stdio.h>
#pragma once

class Snake
{
public:
	//The dimensions of the snake
	static const int SNAKE_WIDTH = 30;
	static const int SNAKE_HEIGHT = 30;

	//Max velocity of the snake
	static const int SNAKE_VEL = 10;

	//Initializes the Snake
	Snake();

	//Take user input (key presses) and adjusts the Snake's velocity
	void handleEvent(SDL_Event& e);

	//Moves the snake
	void move(SDL_Surface* screen, SDL_Rect* player);

	//Renders the snake
	SDL_Rect* renderPlayer(SDL_Surface* screen);

	//Sends the snake back to the original starting position
	bool restartPlayer(SDL_Surface* screen, SDL_Rect* player);

private:
	//Snake x and y offset
	int mPosX, mPosY;

	//Snake velocity
	int mVelX, mVelY;

};

