#include "block.h"
#include "../render/m_window.h"
#include "../render/renderable.h"

void loadTextures() {
	if (!GRASS_TEX.loadFromFile("res/grass.jpg") ||
		!DIRT_TEX.loadFromFile("res/dirt.jpg") ||
		!STONE_TEX.loadFromFile("res/stone.jpg") ||
		!DEFAULT_TEX.loadFromFile("res/default.jpg")) {
		std::cout << "Whoops! Unable to load the texture.\n";
	}
}

Block::Block(MWindow& window, int x, int y, std::string type)
: Renderable(window) {

	this->x = x;
	this->y = y;

	if (type == "grass") {
		spr.setTexture(GRASS_TEX, true);
	} else if (type == "dirt") {
		spr.setTexture(DIRT_TEX, true);
	} else if (type == "stone") {
		spr.setTexture(STONE_TEX, true);
	} else {
		spr.setTexture(DEFAULT_TEX, true);
	}

	spr.setPosition(0, 0);
}

void Block::render(MWindow& target) const {
	target.draw(spr);
}
