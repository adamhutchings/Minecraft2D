#include "block.h"
#include "../render/m_window.h"
#include "../render/renderable.h"

Block::Block(MWindow& window, int x, int y, std::string type)
: Renderable(window) {

	str_type = type;

	itemStack = new ItemStack(type, ItemStackState::BLOCK);

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


EntityItem* Block::destroy(M2DWorld& world) {
	ItemStack* is = new ItemStack(itemStack->name, ItemStackState::ENTITY);
	setTypeTo("air");
	return new EntityItem(&world, is, x + 0.5, y + 0.5);
}

void Block::place(M2DWorld& world, ItemStack* i) {
	setTypeTo(i->name);
}

void Block::setTypeTo(std::string type) {
	str_type = type;
	itemStack->name = type;
	if (type != "air") {
		itemStack->loadTexture(type);
	}
}
