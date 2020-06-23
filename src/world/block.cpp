#include "block.h"
#include "../render/m_window.h"
#include "../render/renderable.h"

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
	} else if (type == "air") {
		// No texture for air
	} else {
		spr.setTexture(DEFAULT_TEX, true);
	}

	spr.setPosition(0, 0);
}

void Block::render(MWindow& target) const {
	target.draw(spr);
}
