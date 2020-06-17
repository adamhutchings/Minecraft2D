#include "item_stack.h"

ItemStack::ItemStack(std::string name, int count) {
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
