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
	Enemy(int posX, int posY);

	//Renders the enemy
	void render();

private:
	//Enemy x and y offset
	int mPosX, mPosY;

};

