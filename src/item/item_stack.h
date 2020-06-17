#ifndef ITEM_STACK_H
#define ITEM_STACK_H

#define ITEM_MAX_COUNT 64

#include <string>

// Represents a stack of items in the inventory.

class ItemStack {
public:
	std::string name;
	int count;

	ItemStack(std::string name, int count=1);

	// When two item stacks combine (on ground or in-inventory)
	bool mergeWith(ItemStack& i);
};

#endif // ITEM_STACK_H