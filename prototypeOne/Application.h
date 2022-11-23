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

	SDL_Rect renderRect;

	//Method definition for init()
	bool init();

	//Function to close window
	void close();

	bool startGame();

	SDL_Texture* load(SDL_Renderer* ren, const char* path);

	void loadMedia();

private:

	// Game Media 
	SDL_Texture* playerTex;
	SDL_Texture* letterA_Tex;
	SDL_Texture* letterB_Tex;
	SDL_Texture* letterC_Tex;
	SDL_Texture* letterD_Tex;
	SDL_Texture* letterE_Tex;
	SDL_Texture* letterF_Tex;
	SDL_Texture* letterG_Tex;
	SDL_Texture* letterH_Tex;
	SDL_Texture* letterI_Tex;
	SDL_Texture* letterJ_Tex;
	SDL_Texture* letterK_Tex;
	SDL_Texture* letterL_Tex;
	SDL_Texture* letterM_Tex;
	SDL_Texture* letterN_Tex;
	SDL_Texture* letterO_Tex;
	SDL_Texture* letterP_Tex;
	SDL_Texture* letterQ_Tex;
	SDL_Texture* letterR_Tex;
	SDL_Texture* letterS_Tex;
	SDL_Texture* letterT_Tex;
	SDL_Texture* letterU_Tex;
	SDL_Texture* letterV_Tex;
	SDL_Texture* letterW_Tex;
	SDL_Texture* letterX_Tex;
	SDL_Texture* letterY_Tex;
	SDL_Texture* letterZ_Tex;
};

