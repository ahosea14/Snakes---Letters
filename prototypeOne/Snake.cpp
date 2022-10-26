#include <SDL.h>
#include <stdio.h>
#include "Snake.h"
#include "Application.h"

Snake::Snake() {
	//Initialize offsets
	mPosX = SCREEN_WIDTH / 2;
	mPosY = SCREEN_HEIGHT / 2;

	//Initialize velocity
	mVelX = 0;
	mVelY = 0;
}

//handles user input
void Snake::handleEvent(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_UP: mVelY -= SNAKE_VEL;  break;
		case SDLK_DOWN: mVelY += SNAKE_VEL; break;
		case SDLK_LEFT: mVelX -= SNAKE_VEL; break;
		case SDLK_RIGHT: mVelX += SNAKE_VEL; break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_UP: mVelY += SNAKE_VEL; break;
		case SDLK_DOWN: mVelY -= SNAKE_VEL; break;
		case SDLK_LEFT: mVelX += SNAKE_VEL; break;
		case SDLK_RIGHT: mVelX -= SNAKE_VEL; break;
		}
	}
}

//moves the snake and calls reset function if the snake hits the edge of the screen
void Snake::move(SDL_Surface* screen, SDL_Rect* player) {
	//set position to move player
	mPosX += mVelX;
	mPosY += mVelY;

	//check if player hit wall
	if (mPosX < 0 || mPosX + SNAKE_WIDTH > SCREEN_WIDTH || mPosY < 0 || mPosY + SNAKE_HEIGHT > SCREEN_HEIGHT) {
		restartPlayer(screen, player);
	}
	else {
		SDL_FillRect(screen, player, 0000);
		player->x = mPosX;
		player->y = mPosY;
		SDL_FillRect(screen, player, 0xFF0000FF);
	}
}

//initial rendering function for the snake
SDL_Rect* Snake::renderPlayer(SDL_Surface* screen) {
	SDL_Rect* snakePlayer = new SDL_Rect{ mPosX, mPosY, SNAKE_WIDTH, SNAKE_HEIGHT };
	bool success = true;

	if (screen == NULL) {
		printf("screen not displaying on create player method");
		success = false;
	}
	else {
		if (snakePlayer == NULL) {
			printf("player is null");
		}
		else {
			SDL_FillRect(screen, snakePlayer, 0xFF0000FF);
		}
	}
	return snakePlayer;
}

//function to restart the player
bool Snake::restartPlayer(SDL_Surface* screen, SDL_Rect* player) {
	bool success = true;
	SDL_FillRect(screen, player, 0000);
	mPosX = SCREEN_WIDTH / 2;
	mPosY = SCREEN_HEIGHT / 2;

	if (mPosX != SCREEN_WIDTH / 2 || mPosY != SCREEN_HEIGHT / 2) {
		success = false;
		printf("player failed to restart");
	}
	else {
		player->x = mPosX;
		player->y = mPosY;
		SDL_FillRect(screen, player, 0xFF0000FF);
	}
	return success;
}