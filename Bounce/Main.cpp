#include "Game.h"
#include "stdafx.h"


int main() {
	
	Game myGame(800, 600, "Bounce");
	myGame.Go();

	return EXIT_SUCCESS;
}