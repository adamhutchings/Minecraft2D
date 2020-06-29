#include "block.h"
#include "../render/m_window.h"
#include "../render/renderable.h"

Block::Block(MWindow& window, int x, int y, std::string type)
: Renderable(window) {

	str_type = type;

	this->x = x;
	this->y = y;

	loadTexture(type);

	spr.setPosition(0, 0);
}

void Block::render(MWindow& target) const {
	target.draw(spr);
}

void Block::loadTexture(std::string tex) {
	if (tex == "grass") {
		spr.setTexture(GRASS_TEX, true);
	} else if (tex == "dirt") {
		spr.setTexture(DIRT_TEX, true);
	} else if (tex == "stone") {
		spr.setTexture(STONE_TEX, true);
	} else if (tex == "air") {
		// No texture for air
	} else {
		spr.setTexture(DEFAULT_TEX, true);
	}
}
