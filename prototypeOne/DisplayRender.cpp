#include "DisplayRender.h"
#include "Application.h"

DisplayRender::DisplayRender() {
	mWidth = 0;
	mHeight = 0;
}

DisplayRender::~DisplayRender() {
	free();
}

void DisplayRender::free() {

}