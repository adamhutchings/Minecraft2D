#include "item.h"
#include "../item/item_stack.h"

EntityItem::EntityItem(M2DWorld* o_world, ItemStack* is, double x, double y)
: Entity(o_world, x, y) {
	itemStackObj = is;
	itemStackObj->setItemState(ItemStackState::ENTITY);
}

int EntityItem::getSpawnHealth() {
	return ITEM_HEALTH;
}

void EntityItem::render(MWindow& window) const {
	window.draw(itemStackObj->spr);
}
bool EntityItem::collidedBelow() {
	return false;
}

bool EntityItem::collidedAbove() {
	return false;
}

bool EntityItem::collidedLeft () {
	return false;
}

bool EntityItem::collidedRight() {
	return false;
}


void EntityItem::updateSpritePosition(MWindow& relativeTo) {
	itemStackObj->spr.setPosition(x*200 + 40 - relativeTo.xShift,  -y*200 + 40 - relativeTo.yShift);
}
