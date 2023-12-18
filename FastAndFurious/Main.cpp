#include "Game.h"
#include "stdafx.h"

Texture texture;
Sprite sprite;

int main() {
	
	Game myGame(800, 600, "Fast & Furious");
	myGame.Go();

	return EXIT_SUCCESS;
}