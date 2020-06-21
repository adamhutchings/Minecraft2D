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

void startNewGame(MWindow& window) {
	window.state = MAIN_GAME;
	M2DWorld* world = new M2DWorld(window);
	Player* player = new Player(*world);
	MButton* button;
	// Get rid of all the buttons
	for (Renderable* object : window.objects) {
		button = dynamic_cast<MButton*>(object);
		if (button) {
			button->hidden = true;
		}
	}
}

void mExit(MWindow& window) {
	exit(EXIT_SUCCESS);
}

int main() {

	// Setup
	loadTextures();

	loadButtonFont();
	
	// For now, just create a new window
	MWindow wn(WN_WIDTH, WN_HEIGHT, "2D Minecraft");
	wn.color = WN_BG_COLOR;

	// Buttons for actions
	MButton startGame(wn, startNewGame, "New Game", sf::Color(100, 100, 100), 1000, 1000);
	MButton retButton(wn, returnToGame, "Resume", sf::Color(100, 100, 100), 1000, 800, true);
	MButton exitButton(wn, mExit, "Quit", sf::Color(100, 100, 100), 1000, 1200, true);
	wn.cycle();

	return 0;

}
