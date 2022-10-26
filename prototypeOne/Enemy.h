#include <SDL.h>
#include <stdio.h>
#pragma once

class Enemy
{
public:
	//The dimensions of the enemy
	static const int ENEMY_WIDTH = 30;
	static const int ENEMY_HEIGHT = 30;

	//Initializes the enemy
	Enemy();

	//Renders the enemy
	void renderEnemy(SDL_Surface* screen);

private:
	//Enemy x and y offset
	int mPosX, mPosY;

	//Number of enemies to render
	int numEnemies = 5;

};

