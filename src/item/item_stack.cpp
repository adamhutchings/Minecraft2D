#include "item_stack.h"

ItemStack::ItemStack(std::string name, ItemStackState i, int count) {
	itemStackState = i;
	this->name = name;
	this->count = count;
	loadTexture(name);
	spr.setPosition(0, 0);
}

bool ItemStack::mergeWith(ItemStack& i) {
	// this gets all the items added to it, returning true if both stacks combine
	if (this->count + i.count <= ITEM_MAX_COUNT) {
		this->count += i.count;
		return true;
	} else {
		i.count -= (ITEM_MAX_COUNT - this->count);
		this->count = ITEM_MAX_COUNT;
		return false;
	}
}

void ItemStack::loadTexture(std::string tex) {
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

ItemStackState& ItemStack::getItemState() {
	return itemStackState;
}

void ItemStack::setItemState(const ItemStackState i) {
	itemStackState = i;
	if (i == ItemStackState::BLOCK) {
		spr.setScale(1, 1);
	} else if (i == ItemStackState::ENTITY || i == ItemStackState::INVENTORY) {
		spr.setScale(ITEM_ENTITY_SIZE, ITEM_ENTITY_SIZE);
	} // We'll have a proper size for INVENTORY later.
}
