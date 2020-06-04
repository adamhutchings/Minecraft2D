#include "block.h"

void loadTextures() {
	if (!GRASS_TEX  .loadFromFile("res/grass.jpg") ||
		!DEFAULT_TEX.loadFromFile("res/default.jpg")) {
		std::cout << "Whoops! Unable to load the texture.\n";
	}
}

Block::Block(MWindow& window, std::string type)
: Renderable(window, true) {
	// For now, always render in the center of the screen
	tex.setPosition(900, 900);
	if (type == "grass") {
		tex.setTexture(GRASS_TEX, true);
	} else {
		tex.setTexture(DEFAULT_TEX, true);
	}
}

void Block::render(sf::RenderTarget& target) const {
	target.draw(tex);
}
