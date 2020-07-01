#include "block.h"
#include "../render/m_window.h"
#include "../render/renderable.h"

Block::Block(MWindow& window, int x, int y, std::string type)
: Renderable(window) {

	str_type = type;

	itemStack = new ItemStack(type);

	this->x = x;
	this->y = y;
}

void Block::render(MWindow& target) const {
	target.draw(itemStack->spr);
}

void Block::updateSpritePosition(MWindow& relativeTo) {
	itemStack->spr.setPosition(x*200 + 100 - relativeTo.xShift,  -y*200 + 100 - relativeTo.yShift);
}
