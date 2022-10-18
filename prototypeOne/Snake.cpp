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

void Snake::handleEvent(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_UP: mVelY -= SNAKE_VEL; break;
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

void Snake::move() {
	mPosX += mVelX;
	if ((mPosX < 0) || (mPosX + SNAKE_WIDTH > SCREEN_WIDTH)) {
		mPosX -= mVelX;
	}

	mPosY += mVelY;
	if ((mPosY < 0) || (mPosY + SNAKE_HEIGHT > SCREEN_WIDTH)) {
		mPosY -= mVelY;
	}
}