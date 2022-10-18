#pragma once
class DisplayRender
{
public:
	//Initiates the display
	DisplayRender();

	//Deallocates memory
	~DisplayRender();

	//Deallocates texture
	void free();

	//Renders texture at a given point
	void render();

	//Get image dimensions
	int getWidth();
	int getHeight();

private:
	//Image dimensions
	int mWidth, mHeight;
};

