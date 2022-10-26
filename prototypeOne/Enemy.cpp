#include <time.h>
#include "Enemy.h"
#include <stdlib.h>

//default constructor
Enemy::Enemy() {
	mPosX = 0;
	mPosY = 0;
}

//creates the enemy rectangle and stores the location of each rectangle in a nested array
void Enemy::renderEnemy(SDL_Surface* screen) {
	for (int i = 1; i <= numEnemies; i++) {
		SDL_Rect* enemy = new SDL_Rect{ (rand() % (640 - ENEMY_WIDTH)), (rand() % (480 - ENEMY_HEIGHT)), ENEMY_WIDTH, ENEMY_HEIGHT };
		SDL_FillRect(screen, enemy, 0xFF0000FF);
	}
}