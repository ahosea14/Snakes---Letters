#include <SDL.h>
#include <stdio.h>
#include<iostream>
#include <SDL_image.h>
#include "Application.h"
#include "Snake.h"
#include "Enemy.h"

	//Screen dimensions 
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	//Declares the window and the screen that the items will be drawn to
	SDL_Window* window = NULL;
	SDL_Renderer* cRenderer = NULL;
	SDL_Texture* cTexture = NULL;

	//method definition for init()
	bool Application::init() {
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
				cRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
				if (cRenderer == NULL) {
					printf("SDL Renderer could not be created. SDL_Error: %s\n", SDL_GetError());
					success = false;
				}
				else {
					loadMedia();
					SDL_SetRenderDrawColor(cRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					int imgFlags = IMG_INIT_PNG;
				}
			}
		}
		return success;
	}

	//function to close window
	void Application::close() {
		SDL_RenderClear(cRenderer);
		cRenderer = NULL;

		SDL_DestroyWindow(window);
		window = NULL;

		SDL_Quit();
	}

	bool Application::startGame() {
		bool success = true;
		SDL_RenderClear(cRenderer);
		Snake player;
		SDL_Rect* playerRender = player.renderPlayer(cRenderer, playerTex);
		Enemy enemy;
		enemy.startEnemy(cRenderer, letterA_Tex);
		bool quit = false;
		SDL_Event playerInput;
		while (!quit) {
			while (SDL_PollEvent(&playerInput) != 0) {
				if (playerInput.type == SDL_QUIT) {
					quit = true;
				}
				else {
					loadMedia();
					player.handleEvent(playerInput);
					SDL_RenderClear(cRenderer);
					player.move(cRenderer, playerRender, playerTex);
					enemy.renderEnemy(cRenderer, letterA_Tex);
					SDL_RenderPresent(cRenderer);
				}
			}
		}
		return success;
	}

	SDL_Texture* Application::load(SDL_Renderer* ren, const char* path) {
		SDL_Texture* tex = IMG_LoadTexture(ren, path);

		SDL_Rect renderRect;
		renderRect.x = 0;
		renderRect.y = 0;
		renderRect.w = 50;
		renderRect.h = 50;
		if (tex == NULL) {
			printf("SDL Image could not be created. IMG_Error: %s\n", IMG_GetError());
		}
		else {
			SDL_RenderClear(ren);
			SDL_RenderCopy(ren, tex, NULL, &renderRect);
			SDL_RenderPresent(ren);
		}
		return tex;
	}

	void Application::loadMedia() {
		playerTex = IMG_LoadTexture(cRenderer, "../letters/ScrittaB2.png");
		SDL_Texture* playerTex = SDL_CreateTexture(cRenderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
		SDL_SetTextureBlendMode(playerTex, SDL_BLENDMODE_BLEND);

		letterA_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaA1.png");
		letterB_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaB2.png");
		letterC_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaC3.png");
		letterD_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaD4.png");
		letterE_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaE5.png");
		letterF_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaF6.png");
		letterG_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaG7.png");
		letterH_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaH8.png");
		letterI_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaI9.png");
		letterJ_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaJ10.png");
		letterK_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaK11.png");
		letterL_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaL12.png");
		letterM_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaM13.png");
		letterN_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaN14.png");
		letterO_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaO15.png");
		letterP_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaP16.png");
		letterQ_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaQ17.png");
		letterR_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaR18.png");
		letterS_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaS19.png");
		letterT_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaT20.png");
		letterU_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaU21.png");
		letterV_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaV22.png");
		letterW_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaW23.png");
		letterX_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaX24.png");
		letterY_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaY25.png");
		letterZ_Tex = IMG_LoadTexture(cRenderer, "../letters/ScrittaZ26.png");
	}

