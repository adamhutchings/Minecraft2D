#include "item_stack.h"

ItemStack::ItemStack(MWindow& window, std::string name, int count)
: Renderable(window) {
	itemStackState = ItemStackState::ENTITY;
	this->name = name;
	this->count = count;
}

bool ItemStack::mergeWith(ItemStack& i) {
	// this gets all the items added to it, returning true if both stacks combine
	if (this->count + i.count <= ITEM_MAX_COUNT) {
		this->count += i.count;
		return true;
	} else {
		i.count -= (64 - this->count);
		this->count = ITEM_MAX_COUNT;
		return false;
	}
}

void ItemStack::render(MWindow& window) const {
	// We'll get to this later
}
