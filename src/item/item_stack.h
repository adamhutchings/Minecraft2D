#ifndef ITEM_STACK_H
#define ITEM_STACK_H

#define ITEM_MAX_COUNT 64

#include <string>
#include "../render/renderable.h"
#include "../render/m_window.h"
#include "../world/block.h"

enum ItemStackState {
	ENTITY,
	BLOCK,
	INVENTORY
};

// Represents a stack of items in the inventory.

class ItemStack {
public:
	sf::Sprite spr; // This will get rendered in different contexts
	std::string name;
	int count;
	ItemStackState itemStackState;

	ItemStack(std::string name, ItemStackState i, int count=1);

	// When two item stacks combine (on ground or in-inventory)
	bool mergeWith(ItemStack& i);

	void loadTexture(std::string tex);

};

#endif // ITEM_STACK_H