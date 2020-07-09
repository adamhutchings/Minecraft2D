#include "item.h"

EntityItem::EntityItem(M2DWorld* o_world, ItemStack* is, double x, double y)
: Entity(o_world, x, y) {
	itemStackObj = is;
	itemStackObj->itemStackState = ItemStackState::ENTITY;
}

int EntityItem::getSpawnHealth() {
	return ITEM_HEALTH;
}

void EntityItem::render(MWindow& window) const {
	// Nothing for now
}
