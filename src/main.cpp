#include "main.h"

void loadButtonFont() {
	if (!M_BUTTON_FONT.loadFromFile("/Library/Fonts/arial.ttf")) {
		std::cout << "Whoops! An error occurred.\n";
		exit(EXIT_FAILURE);
	}
}

void loadTextures() {
	if (!GRASS_TEX.loadFromFile("res/tex/grass.jpg") ||
		!DIRT_TEX.loadFromFile("res/tex/dirt.jpg") ||
		!STONE_TEX.loadFromFile("res/tex/stone.jpg") ||
		!DEFAULT_TEX.loadFromFile("res/tex/default.jpg") ||
		!HEAD_TEX_LEFT.loadFromFile("res/tex/head_left.jpg" ) ||
		!HEAD_TEX_RIGHT.loadFromFile("res/tex/head_right.jpg") ||
		!BODY_TEX.loadFromFile("res/tex/body.jpg")) {
		std::cout << "Whoops! Unable to load the texture.\n";
		exit(EXIT_FAILURE);
	}
}

int main() {

	// Setup
	loadTextures();

	loadButtonFont();
	
	// For now, just create a new window
	MWindow wn(WN_WIDTH, WN_HEIGHT, "2D Minecraft");
	wn.color = WN_BG_COLOR;

	// Let's make a world and a player!
	M2DWorld world(wn);
	Player player(world);

	wn.cycle();

	return 0;

}
