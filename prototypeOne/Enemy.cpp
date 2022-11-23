#include <time.h>
#include "Enemy.h"
#include <stdlib.h>
#include <SDL_image.h>

//default constructor
Enemy::Enemy() {
	mPosX = 0;
	mPosY = 0;
}

//creates the enemy rectangle and stores the location of each rectangle in a nested array
void Enemy::startEnemy(SDL_Renderer* ren, SDL_Texture* enemyTex) {
	for (int i = 0; i <= numEnemies; i++) {
		SDL_Rect* enemy = new SDL_Rect{ (rand() % (640 - ENEMY_WIDTH)), (rand() % (480 - ENEMY_HEIGHT)), ENEMY_WIDTH, ENEMY_HEIGHT };
		enemies[i][0] = enemy->x;
		enemies[i][1] = enemy->y;
		SDL_RenderCopy(ren, enemyTex, NULL, enemy);
		SDL_RenderPresent(ren);
	}
}

void Enemy::renderEnemy(SDL_Renderer* ren, SDL_Texture* enemyTex) {
	for (int i = 0; i <= numEnemies; i++) {
		SDL_Rect* enemy = new SDL_Rect{ enemies[i][0], enemies[i][1], ENEMY_WIDTH, ENEMY_HEIGHT };
		SDL_RenderCopy(ren, enemyTex, NULL, enemy);
		SDL_RenderPresent(ren);
	}
}