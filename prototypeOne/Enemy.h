#pragma once
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>


class Enemy
{
public:
	//The dimensions of the enemy
	static const int ENEMY_WIDTH = 30;
	static const int ENEMY_HEIGHT = 30;

	//Number of enemies
	static const int numEnemies = 5;

	//Initializes the enemy
	Enemy();

	//Renders the enemy
	void startEnemy(SDL_Renderer* ren, SDL_Texture* enemyTex);

	void renderEnemy(SDL_Renderer* ren, SDL_Texture* enemyTex);

private:
	//Enemy x and y offset
	int mPosX, mPosY;

	//Allocated to hold the x and y coordinates of the enemies 
	int  enemies[numEnemies][2];
};

