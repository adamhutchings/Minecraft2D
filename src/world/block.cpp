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
	if (itemStack->name != "air") // Don't bother rendering for air
	target.draw(itemStack->spr);
}

void Block::updateSpritePosition(MWindow& relativeTo) {
	itemStack->spr.setPosition(x*200 + 100 - relativeTo.xShift,  -y*200 + 100 - relativeTo.yShift);
}

ItemStack* Block::destroy() {
	ItemStack* is = new ItemStack(itemStack->name);
	setTypeTo("air");
	return is;
}

void Block::setTypeTo(std::string type) {
	str_type = type;
	itemStack->name = type;
	if (type != "air") {
		itemStack->loadTexture(type);
	}
}
